# Changelog

## 1.0.0
- Initial portability-complete release (no callbacks/varargs).
- Generated shim + FFI pipeline stabilized through Phase 9.
- 64-bit pointer roundtrip bug fixed and covered by deterministic test.
- Public ergonomic Disturb API added in `disturb_bindings/raylib.dist`.
- User-facing examples added in `examples_user/`.
- Headless-friendly regression suites and conformance targets included.

### Known limitations
- 12 callback/varargs APIs are intentionally omitted.
