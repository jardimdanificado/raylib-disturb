#!/usr/bin/env python3
import collections
import json
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parent.parent
H_PATH = ROOT / 'raylib/src/raylib.h'
TOOLS = ROOT / 'tools'
GEN = ROOT / 'generated'
GEN.mkdir(exist_ok=True)


def strip_comments(s: str) -> str:
    s = re.sub(r'/\*.*?\*/', '', s, flags=re.S)
    s = re.sub(r'//.*?$', '', s, flags=re.M)
    return s


def collapse_ws(s: str) -> str:
    return re.sub(r'\s+', ' ', s).strip()


def split_top_level_commas(s: str):
    parts, cur = [], []
    dpar = dbr = dbrc = 0
    i = 0
    while i < len(s):
        ch = s[i]
        if ch == '(':
            dpar += 1
        elif ch == ')':
            dpar = max(0, dpar - 1)
        elif ch == '[':
            dbr += 1
        elif ch == ']':
            dbr = max(0, dbr - 1)
        elif ch == '{':
            dbrc += 1
        elif ch == '}':
            dbrc = max(0, dbrc - 1)
        if ch == ',' and dpar == dbr == dbrc == 0:
            p = ''.join(cur).strip()
            if p:
                parts.append(p)
            cur = []
        else:
            cur.append(ch)
        i += 1
    tail = ''.join(cur).strip()
    if tail:
        parts.append(tail)
    return parts


def c_ident(s: str) -> bool:
    return bool(re.fullmatch(r'[A-Za-z_]\w*', s))


def is_char_ptr(t: str) -> bool:
    k = re.sub(r'\s+', '', t).lower()
    return k in {'char*', 'constchar*', 'char*const', 'constchar*const'}


def parse_param(p: str, idx: int):
    p = collapse_ws(p)
    if not p or p == 'void':
        return None
    if p == '...':
        return {'type_string': '...', 'name_string': '', 'decl': '...', 'is_vararg': True, 'is_callback': False}

    mcb = re.search(r'\(\s*\*\s*([A-Za-z_]\w*)\s*\)', p)
    if mcb:
        return {'type_string': p, 'name_string': mcb.group(1), 'decl': p, 'is_vararg': False, 'is_callback': True}

    # type + name (+optional array suffix)
    m = re.match(r'^(.*?)([A-Za-z_]\w*)(\s*(?:\[[^\]]*\]\s*)*)$', p)
    if m:
        t = collapse_ws((m.group(1) or '').strip())
        n = m.group(2)
        arr = (m.group(3) or '').strip()
        if arr:
            t = collapse_ws(f"{t} {arr}")
        if not t:
            return {'type_string': p, 'name_string': f'p{idx}', 'decl': p, 'is_vararg': False, 'is_callback': False}
        return {'type_string': t, 'name_string': n, 'decl': p, 'is_vararg': False, 'is_callback': False}

    return {'type_string': p, 'name_string': f'p{idx}', 'decl': p, 'is_vararg': False, 'is_callback': False}


primitive_tokens = {
    'void', 'bool', 'char', 'signed', 'unsigned', 'short', 'int', 'long', 'float', 'double',
    'size_t', 'intptr_t', 'uintptr_t', 'va_list', 'const', 'volatile'
}


def is_primitive_type(t: str) -> bool:
    k = t.strip()
    if '[' in k or ']' in k:
        return False
    if '*' in k:
        return is_char_ptr(k)
    words = [w for w in re.split(r'\s+', k) if w]
    return all(w.lower() in primitive_tokens for w in words)


def ffi_map_type(t: str, known_types: set[str]):
    tt = collapse_ws(t)
    key = re.sub(r'\s+', '', tt).lower()
    while key.startswith('const'):
        key = key[5:]
    if key == 'void':
        return 'void', False
    if '*' in key:
        if is_char_ptr(tt):
            return 'char*', False
        return 'void*', False
    if key == 'float':
        return 'f32', False
    if key == 'double':
        return 'f32', True
    if any(k in key for k in ['int', 'long', 'short', 'bool', 'char', 'size_t', 'intptr_t', 'uintptr_t']):
        return 'i32', False
    if type_looks_named(tt, known_types):
        return 'void*', True
    return 'void*', True


def type_looks_named(t: str, known_types: set[str]) -> bool:
    if 'struct ' in t:
        return True
    for tok in re.split(r'[^A-Za-z0-9_]+', t):
        if tok and tok in known_types:
            return True
    return False


def parse_prototype(statement: str):
    s = collapse_ws(statement)
    if not s.endswith(';'):
        return None, 'no_semicolon'
    ss = s[:-1].strip()
    op = ss.find('(')
    if op < 0:
        return None, 'no_open_paren'

    depth = 0
    cp = -1
    for j in range(op, len(ss)):
        if ss[j] == '(':
            depth += 1
        elif ss[j] == ')':
            depth -= 1
            if depth == 0:
                cp = j
                break
    if cp < 0:
        return None, 'unbalanced_paren'

    left = ss[:op].strip()
    right = ss[cp + 1:].strip()
    if right:
        return None, 'trailing_tokens'

    toks = left.split()
    if len(toks) < 2:
        return None, 'left_too_short'

    raw_name = toks[-1]
    name = raw_name.lstrip('*').strip()
    if not c_ident(name):
        return None, 'bad_name'

    ret = ' '.join(t for t in toks[:-1] if t not in {'RLAPI', 'extern'})
    ptr_count = len(raw_name) - len(name)
    if ptr_count > 0:
        ret = (ret + ' ' + ('*' * ptr_count)).strip()
    ret = collapse_ws(ret)

    params = []
    params_txt = ss[op + 1:cp].strip()
    if params_txt and params_txt != 'void':
        for idx, rp in enumerate(split_top_level_commas(params_txt)):
            pp = parse_param(rp, idx)
            if pp is not None:
                params.append(pp)

    return {
        'name': name,
        'return_type': ret,
        'params': params,
        'signature': ss,
    }, None


text = H_PATH.read_text(encoding='utf-8', errors='ignore')

# Collect defines (from original with preprocessor)
defines = []
lines = text.splitlines()
i = 0
while i < len(lines):
    st = lines[i].strip()
    if st.startswith('#define '):
        full = st
        while full.endswith('\\') and i + 1 < len(lines):
            full = full[:-1].rstrip() + ' ' + lines[i + 1].strip()
            i += 1
        full = re.sub(r'/\*.*?\*/', '', full)
        full = re.sub(r'//.*$', '', full).strip()
        m = re.match(r'^#define\s+([A-Za-z_]\w*)(?:\s+(.*))?$', full)
        if m:
            defines.append({'name': m.group(1), 'value': (m.group(2) or '').strip()})
    i += 1

# Remove preprocessor + comments for structural parsing
no_pp = re.sub(r'^\s*#.*$', '', text, flags=re.M)
clean = strip_comments(no_pp)

# typedef structs
typedef_structs = []
known_types = set()
for m in re.finditer(r'typedef\s+struct\s*([A-Za-z_]\w*)?\s*\{(.*?)\}\s*([A-Za-z_]\w*)\s*;', clean, flags=re.S):
    tag = (m.group(1) or '').strip()
    body = collapse_ws(m.group(2))
    name = m.group(3).strip()
    typedef_structs.append({'name': name, 'tag': tag, 'fields_text': body})
    known_types.add(name)

# forward declarations
for m in re.finditer(r'typedef\s+struct\s+[A-Za-z_]\w*\s+([A-Za-z_]\w*)\s*;', clean):
    known_types.add(m.group(1))

# enums
enums = []
for m in re.finditer(r'typedef\s+enum\s*(?:[A-Za-z_]\w*)?\s*\{(.*?)\}\s*([A-Za-z_]\w*)\s*;', clean, flags=re.S):
    body = m.group(1)
    name = m.group(2)
    known_types.add(name)
    items = []
    for ent in split_top_level_commas(body):
        if not ent:
            continue
        if '=' in ent:
            n, v = ent.split('=', 1)
            n = n.strip()
            if c_ident(n):
                items.append({'name': n, 'value': collapse_ws(v)})
        else:
            n = ent.strip()
            if c_ident(n):
                items.append({'name': n})
    enums.append({'name': name, 'enumerators': items})

# typedef aliases
for m in re.finditer(r'typedef\s+([^;(){}]+?)\s+([A-Za-z_]\w*)\s*;', clean):
    known_types.add(m.group(2))

# function prototypes from RLAPI declarations
functions = []
skipped = []
for m in re.finditer(r'\bRLAPI\b\s+([^;]+?);', clean, flags=re.S):
    candidate = collapse_ws('RLAPI ' + m.group(1) + ';')
    parsed, err = parse_prototype(candidate)
    if parsed is None:
        skipped.append({'kind': 'function', 'reason': err, 'text': candidate})
        continue

    params = parsed['params']
    has_vararg = any(p['is_vararg'] for p in params)
    has_callback = any(
        p['is_callback'] or bool(re.search(r'\b\w*Callback\b', p['type_string']))
        for p in params
    )
    has_ptr_other = any(
        ('*' in p['type_string'] and not is_char_ptr(p['type_string'])) or ('[' in p['type_string'])
        for p in params
    )
    has_named = type_looks_named(parsed['return_type'], known_types) or any(type_looks_named(p['type_string'], known_types) for p in params)
    all_prim = is_primitive_type(parsed['return_type']) and all(is_primitive_type(p['type_string']) for p in params if not p['is_vararg'])

    if has_vararg or has_callback:
        cls = 'D'
    elif has_ptr_other:
        cls = 'C'
    elif has_named or not all_prim:
        cls = 'B'
    else:
        cls = 'A'

    mm = re.match(r'([A-Z]?[a-z]+)', parsed['name'])
    module = (mm.group(1).lower() if mm else parsed['name'].lower())

    functions.append({
        'name': parsed['name'],
        'return_type': parsed['return_type'],
        'params': [{'type_string': p['type_string'], 'name_string': p['name_string'], 'decl': p['decl']} for p in params],
        'class': cls,
        'module': module,
        'has_callback': has_callback,
        'has_vararg': has_vararg,
        'signature': parsed['signature'],
    })

# deterministic
functions.sort(key=lambda x: x['name'])
enums.sort(key=lambda x: x['name'])
defines.sort(key=lambda x: x['name'])
typedef_structs.sort(key=lambda x: x['name'])
skipped.sort(key=lambda x: (x['kind'], x['reason'], x['text']))

by_complexity = {'A': 0, 'B': 0, 'C': 0, 'D': 0}
for f in functions:
    by_complexity[f['class']] += 1
by_module = dict(sorted(collections.Counter(f['module'] for f in functions).items()))

stats = {
    'total_functions': len(functions),
    'total_enums': len(enums),
    'total_defines': len(defines),
    'total_typedef_structs': len(typedef_structs),
    'total_skipped': len(skipped),
    'by_complexity': by_complexity,
    'by_module': by_module,
}

inventory = {
    'functions': functions,
    'enums': enums,
    'defines': defines,
    'typedef_structs': typedef_structs,
    'skipped': skipped,
    'stats': stats,
}
(TOOLS / 'raylib_inventory.json').write_text(json.dumps(inventory, indent=2) + '\n', encoding='utf-8')

# shim.h
shim_h = [
    '#ifndef GENERATED_RAYLIB_SHIM_H',
    '#define GENERATED_RAYLIB_SHIM_H',
    '',
    '#include <stddef.h>',
    '#include <stdint.h>',
    '#include <stdbool.h>',
    '#include "../raylib/src/raylib.h"',
    '',
    '#ifdef __cplusplus',
    'extern "C" {',
    '#endif',
    '',
]
for f in functions:
    if f['class'] != 'A':
        shim_h.append(f'// TODO({f["class"]}): complex signature may need flattening')
    decl = ', '.join(p['decl'] for p in f['params']) if f['params'] else 'void'
    shim_h.append(f'{f["return_type"]} rl_{f["name"]}({decl});')
shim_h += ['', '#ifdef __cplusplus', '}', '#endif', '', '#endif', '']
(GEN / 'raylib_shim.h').write_text('\n'.join(shim_h), encoding='utf-8')

# shim.c

def default_return(ret: str) -> str:
    r = ret.strip()
    if r == 'void':
        return '    return;'
    if '*' in r:
        return '    return NULL;'
    if r == 'bool':
        return '    return false;'
    if re.fullmatch(r'(?:unsigned\s+)?(?:char|short|int|long|long\s+long|float|double|size_t|intptr_t|uintptr_t)', r):
        return '    return 0;'
    return f'    return ({r}){{0}};'

shim_c = ['#include "raylib_shim.h"', '']
for f in functions:
    decl = ', '.join(p['decl'] for p in f['params']) if f['params'] else 'void'
    shim_c.append(f'{f["return_type"]} rl_{f["name"]}({decl})')
    shim_c.append('{')
    shim_c.append(f'    // TODO: implement wrapper for {f["name"]}')
    for p in f['params']:
        if p['name_string']:
            shim_c.append(f'    (void){p["name_string"]};')
    if f['class'] != 'A':
        shim_c.append(f'    // TODO: class {f["class"]} requires manual handling')
    shim_c.append(default_return(f['return_type']))
    shim_c.append('}')
    shim_c.append('')
(GEN / 'raylib_shim.c').write_text('\n'.join(shim_c), encoding='utf-8')

# ffi.dist
ffi_lines = []
ffi_todos = []
ffi_skipped = []
for f in functions:
    if f['class'] == 'D':
        ffi_skipped.append(f)
        continue
    rm, rtodo = ffi_map_type(f['return_type'], known_types)
    if rtodo:
        ffi_todos.append(f'return {f["name"]}: {f["return_type"]}')
    pms = []
    for p in f['params']:
        if p['decl'].strip() == '...':
            continue
        pm, ptodo = ffi_map_type(p['type_string'], known_types)
        if ptodo:
            ffi_todos.append(f'param {f["name"]}: {p["type_string"]}')
        pms.append(pm)
    ffi_lines.append(f'{rm} rl_{f["name"]}({", ".join(pms)})')

ffi_out = [
    '// Auto-generated by tools/raylib_gen.py',
    '// Mapping: int/bool->i32, float/double->f32, char*->char*, other ptr/struct->void*',
    'shim_path = "./libraylib_disturb.so";',
    'raylib_shim = ffi.load(shim_path,',
]
for i, sig in enumerate(ffi_lines):
    comma = ',' if i < len(ffi_lines) - 1 else ''
    ffi_out.append(f'  "{sig}"{comma}')
ffi_out.append(');')
ffi_out.append('')
if ffi_skipped:
    ffi_out.append('// TODO: class D callbacks/varargs')
    for f in ffi_skipped:
        ffi_out.append(f'// - rl_{f["name"]}: {f["signature"]}')
    ffi_out.append('')
if ffi_todos:
    ffi_out.append('// TODO: unknown mappings')
    for t in sorted(set(ffi_todos)):
        ffi_out.append(f'// - {t}')
(GEN / 'raylib_ffi.dist').write_text('\n'.join(ffi_out) + '\n', encoding='utf-8')

# report
hard = [f for f in functions if f['class'] == 'D'] + [f for f in functions if f['class'] == 'C'] + [f for f in functions if f['class'] == 'B']
callbacks = [f for f in functions if f['has_callback'] or f['has_vararg']]

report = [
    '# Raylib Header Inventory Report',
    '',
    'Generated by `tools/raylib_gen.py`.',
    '',
    '## Totals',
    '',
    f'- Total functions: {len(functions)}',
    f'- Class A: {by_complexity["A"]}',
    f'- Class B: {by_complexity["B"]}',
    f'- Class C: {by_complexity["C"]}',
    f'- Class D: {by_complexity["D"]}',
    f'- Enums: {len(enums)}',
    f'- Defines: {len(defines)}',
    f'- Typedef structs: {len(typedef_structs)}',
    f'- Skipped parse entries: {len(skipped)}',
    '',
    '## Top 20 Hardest Functions',
    '',
]
if hard:
    for f in hard[:20]:
        report.append(f'- [{f["class"]}] {f["name"]} :: `{f["signature"]}`')
else:
    report.append('- (none)')
report += ['', '## Callbacks / Varargs', '']
if callbacks:
    for f in callbacks:
        tags = []
        if f['has_callback']:
            tags.append('callback')
        if f['has_vararg']:
            tags.append('varargs')
        report.append(f'- {f["name"]} ({", ".join(tags)}) :: `{f["signature"]}`')
else:
    report.append('- (none)')
report += ['', '## Skipped Entries', '']
if skipped:
    for s in skipped:
        report.append(f'- [{s["kind"]}] {s["reason"]} :: `{s["text"]}`')
else:
    report.append('- (none)')
(GEN / 'report.md').write_text('\n'.join(report) + '\n', encoding='utf-8')

print(f"raylib_gen.py: functions={len(functions)} enums={len(enums)} defines={len(defines)} structs={len(typedef_structs)} skipped={len(skipped)}")
