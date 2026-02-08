#ifndef GENERATED_RAYLIB_SHIM_H
#define GENERATED_RAYLIB_SHIM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "../raylib/src/raylib.h"

#ifdef __cplusplus
extern "C" {
#endif

// TODO(D): complex signature may need flattening
void rl_AttachAudioMixedProcessor(AudioCallback processor);
// TODO(D): complex signature may need flattening
void rl_AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor);
void rl_BeginBlendMode(int mode);
void rl_BeginDrawing(void);
// TODO(B): complex signature may need flattening
void rl_BeginMode2D(Camera2D camera);
// TODO(B): complex signature may need flattening
void rl_BeginMode3D(Camera3D camera);
void rl_BeginScissorMode(int x, int y, int width, int height);
// TODO(B): complex signature may need flattening
void rl_BeginShaderMode(Shader shader);
// TODO(B): complex signature may need flattening
void rl_BeginTextureMode(RenderTexture2D target);
// TODO(B): complex signature may need flattening
void rl_BeginVrStereoMode(VrStereoConfig config);
// TODO(B): complex signature may need flattening
bool rl_ChangeDirectory(const char *dirPath);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
// TODO(C): complex signature may need flattening
bool rl_CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold);
// TODO(C): complex signature may need flattening
bool rl_CheckCollisionPointPoly(Vector2 point, const Vector2 *points, int pointCount);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionPointRec(Vector2 point, Rectangle rec);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionRecs(Rectangle rec1, Rectangle rec2);
// TODO(B): complex signature may need flattening
bool rl_CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);
// TODO(B): complex signature may need flattening
void rl_ClearBackground(Color color);
void rl_ClearWindowState(unsigned int flags);
void rl_CloseAudioDevice(void);
void rl_CloseWindow(void);
// TODO(C): complex signature may need flattening
const char * rl_CodepointToUTF8(int codepoint, int *utf8Size);
// TODO(B): complex signature may need flattening
Color rl_ColorAlpha(Color color, float alpha);
// TODO(B): complex signature may need flattening
Color rl_ColorAlphaBlend(Color dst, Color src, Color tint);
// TODO(B): complex signature may need flattening
Color rl_ColorBrightness(Color color, float factor);
// TODO(B): complex signature may need flattening
Color rl_ColorContrast(Color color, float contrast);
// TODO(B): complex signature may need flattening
Color rl_ColorFromHSV(float hue, float saturation, float value);
// TODO(B): complex signature may need flattening
Color rl_ColorFromNormalized(Vector4 normalized);
// TODO(B): complex signature may need flattening
bool rl_ColorIsEqual(Color col1, Color col2);
// TODO(B): complex signature may need flattening
Color rl_ColorLerp(Color color1, Color color2, float factor);
// TODO(B): complex signature may need flattening
Vector4 rl_ColorNormalize(Color color);
// TODO(B): complex signature may need flattening
Color rl_ColorTint(Color color, Color tint);
// TODO(B): complex signature may need flattening
Vector3 rl_ColorToHSV(Color color);
// TODO(B): complex signature may need flattening
int rl_ColorToInt(Color color);
// TODO(C): complex signature may need flattening
unsigned char * rl_CompressData(const unsigned char *data, int dataSize, int *compDataSize);
// TODO(C): complex signature may need flattening
unsigned int rl_ComputeCRC32(unsigned char *data, int dataSize);
// TODO(C): complex signature may need flattening
unsigned int * rl_ComputeMD5(unsigned char *data, int dataSize);
// TODO(C): complex signature may need flattening
unsigned int * rl_ComputeSHA1(unsigned char *data, int dataSize);
// TODO(C): complex signature may need flattening
unsigned int * rl_ComputeSHA256(unsigned char *data, int dataSize);
// TODO(C): complex signature may need flattening
unsigned char * rl_DecodeDataBase64(const char *text, int *outputSize);
// TODO(C): complex signature may need flattening
unsigned char * rl_DecompressData(const unsigned char *compData, int compDataSize, int *dataSize);
// TODO(D): complex signature may need flattening
void rl_DetachAudioMixedProcessor(AudioCallback processor);
// TODO(D): complex signature may need flattening
void rl_DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor);
// TODO(B): complex signature may need flattening
bool rl_DirectoryExists(const char *dirPath);
void rl_DisableCursor(void);
void rl_DisableEventWaiting(void);
// TODO(B): complex signature may need flattening
void rl_DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawBoundingBox(BoundingBox box, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircle(int centerX, int centerY, float radius, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer);
// TODO(B): complex signature may need flattening
void rl_DrawCircleLines(int centerX, int centerY, float radius, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircleLinesV(Vector2 center, float radius, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCircleV(Vector2 center, float radius, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCube(Vector3 position, float width, float height, float length, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCubeV(Vector3 position, Vector3 size, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCubeWires(Vector3 position, float width, float height, float length, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCubeWiresV(Vector3 position, Vector3 size, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawEllipseLinesV(Vector2 center, float radiusH, float radiusV, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawEllipseV(Vector2 center, float radiusH, float radiusV, Color color);
void rl_DrawFPS(int posX, int posY);
void rl_DrawGrid(int slices, float spacing);
// TODO(B): complex signature may need flattening
void rl_DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawLineDashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawLineStrip(const Vector2 *points, int pointCount, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawLineV(Vector2 startPos, Vector2 endPos, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawMesh(Mesh mesh, Material material, Matrix transform);
// TODO(C): complex signature may need flattening
void rl_DrawMeshInstanced(Mesh mesh, Material material, const Matrix *transforms, int instances);
// TODO(B): complex signature may need flattening
void rl_DrawModel(Model model, Vector3 position, float scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawModelPoints(Model model, Vector3 position, float scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawModelPointsEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawModelWires(Model model, Vector3 position, float scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawPixel(int posX, int posY, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPixelV(Vector2 position, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPlane(Vector3 centerPos, Vector2 size, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPoint3D(Vector3 position, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRay(Ray ray, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangle(int posX, int posY, int width, int height, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color bottomRight, Color topRight);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleLines(int posX, int posY, int width, int height, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleRec(Rectangle rec, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRectangleV(Vector2 position, Vector2 size, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSphere(Vector3 centerPos, float radius, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawSplineBasis(const Vector2 *points, int pointCount, float thick, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawSplineBezierCubic(const Vector2 *points, int pointCount, float thick, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawSplineBezierQuadratic(const Vector2 *points, int pointCount, float thick, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawSplineCatmullRom(const Vector2 *points, int pointCount, float thick, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawSplineLinear(const Vector2 *points, int pointCount, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawText(const char *text, int posX, int posY, int fontSize, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);
// TODO(C): complex signature may need flattening
void rl_DrawTextCodepoints(Font font, const int *codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextPro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTexture(Texture2D texture, int posX, int posY, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTextureV(Texture2D texture, Vector2 position, Color tint);
// TODO(B): complex signature may need flattening
void rl_DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawTriangleFan(const Vector2 *points, int pointCount, Color color);
// TODO(B): complex signature may need flattening
void rl_DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawTriangleStrip(const Vector2 *points, int pointCount, Color color);
// TODO(C): complex signature may need flattening
void rl_DrawTriangleStrip3D(const Vector3 *points, int pointCount, Color color);
void rl_EnableCursor(void);
void rl_EnableEventWaiting(void);
// TODO(C): complex signature may need flattening
char * rl_EncodeDataBase64(const unsigned char *data, int dataSize, int *outputSize);
void rl_EndBlendMode(void);
void rl_EndDrawing(void);
void rl_EndMode2D(void);
void rl_EndMode3D(void);
void rl_EndScissorMode(void);
void rl_EndShaderMode(void);
void rl_EndTextureMode(void);
void rl_EndVrStereoMode(void);
// TODO(B): complex signature may need flattening
bool rl_ExportAutomationEventList(AutomationEventList list, const char *fileName);
// TODO(C): complex signature may need flattening
bool rl_ExportDataAsCode(const unsigned char *data, int dataSize, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportFontAsCode(Font font, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportImage(Image image, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportImageAsCode(Image image, const char *fileName);
// TODO(C): complex signature may need flattening
unsigned char * rl_ExportImageToMemory(Image image, const char *fileType, int *fileSize);
// TODO(B): complex signature may need flattening
bool rl_ExportMesh(Mesh mesh, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportMeshAsCode(Mesh mesh, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportWave(Wave wave, const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_ExportWaveAsCode(Wave wave, const char *fileName);
// TODO(B): complex signature may need flattening
Color rl_Fade(Color color, float alpha);
int rl_FileCopy(const char *srcPath, const char *dstPath);
// TODO(B): complex signature may need flattening
bool rl_FileExists(const char *fileName);
int rl_FileMove(const char *srcPath, const char *dstPath);
int rl_FileRemove(const char *fileName);
int rl_FileRename(const char *fileName, const char *fileRename);
int rl_FileTextFindIndex(const char *fileName, const char *search);
int rl_FileTextReplace(const char *fileName, const char *search, const char *replacement);
// TODO(B): complex signature may need flattening
Image rl_GenImageCellular(int width, int height, int tileSize);
// TODO(B): complex signature may need flattening
Image rl_GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);
// TODO(B): complex signature may need flattening
Image rl_GenImageColor(int width, int height, Color color);
// TODO(C): complex signature may need flattening
Image rl_GenImageFontAtlas(const GlyphInfo *glyphs, Rectangle **glyphRecs, int glyphCount, int fontSize, int padding, int packMethod);
// TODO(B): complex signature may need flattening
Image rl_GenImageGradientLinear(int width, int height, int direction, Color start, Color end);
// TODO(B): complex signature may need flattening
Image rl_GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);
// TODO(B): complex signature may need flattening
Image rl_GenImageGradientSquare(int width, int height, float density, Color inner, Color outer);
// TODO(B): complex signature may need flattening
Image rl_GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);
// TODO(B): complex signature may need flattening
Image rl_GenImageText(int width, int height, const char *text);
// TODO(B): complex signature may need flattening
Image rl_GenImageWhiteNoise(int width, int height, float factor);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshCone(float radius, float height, int slices);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshCube(float width, float height, float length);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshCylinder(float radius, float height, int slices);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshHeightmap(Image heightmap, Vector3 size);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshHemiSphere(float radius, int rings, int slices);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshKnot(float radius, float size, int radSeg, int sides);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshPlane(float width, float length, int resX, int resZ);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshPoly(int sides, float radius);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshSphere(float radius, int rings, int slices);
// TODO(C): complex signature may need flattening
void rl_GenMeshTangents(Mesh *mesh);
// TODO(B): complex signature may need flattening
Mesh rl_GenMeshTorus(float radius, float size, int radSeg, int sides);
// TODO(C): complex signature may need flattening
void rl_GenTextureMipmaps(Texture2D *texture);
const char * rl_GetApplicationDirectory(void);
// TODO(B): complex signature may need flattening
Matrix rl_GetCameraMatrix(Camera camera);
// TODO(B): complex signature may need flattening
Matrix rl_GetCameraMatrix2D(Camera2D camera);
int rl_GetCharPressed(void);
// TODO(B): complex signature may need flattening
Image rl_GetClipboardImage(void);
const char * rl_GetClipboardText(void);
// TODO(C): complex signature may need flattening
int rl_GetCodepoint(const char *text, int *codepointSize);
int rl_GetCodepointCount(const char *text);
// TODO(C): complex signature may need flattening
int rl_GetCodepointNext(const char *text, int *codepointSize);
// TODO(C): complex signature may need flattening
int rl_GetCodepointPrevious(const char *text, int *codepointSize);
// TODO(B): complex signature may need flattening
Rectangle rl_GetCollisionRec(Rectangle rec1, Rectangle rec2);
// TODO(B): complex signature may need flattening
Color rl_GetColor(unsigned int hexValue);
int rl_GetCurrentMonitor(void);
unsigned int rl_GetDirectoryFileCount(const char *dirPath);
// TODO(B): complex signature may need flattening
unsigned int rl_GetDirectoryFileCountEx(const char *basePath, const char *filter, bool scanSubdirs);
const char * rl_GetDirectoryPath(const char *filePath);
int rl_GetFPS(void);
const char * rl_GetFileExtension(const char *fileName);
int rl_GetFileLength(const char *fileName);
long rl_GetFileModTime(const char *fileName);
const char * rl_GetFileName(const char *filePath);
const char * rl_GetFileNameWithoutExt(const char *filePath);
// TODO(B): complex signature may need flattening
Font rl_GetFontDefault(void);
float rl_GetFrameTime(void);
int rl_GetGamepadAxisCount(int gamepad);
float rl_GetGamepadAxisMovement(int gamepad, int axis);
int rl_GetGamepadButtonPressed(void);
const char * rl_GetGamepadName(int gamepad);
int rl_GetGestureDetected(void);
float rl_GetGestureDragAngle(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetGestureDragVector(void);
float rl_GetGestureHoldDuration(void);
float rl_GetGesturePinchAngle(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetGesturePinchVector(void);
// TODO(B): complex signature may need flattening
Rectangle rl_GetGlyphAtlasRec(Font font, int codepoint);
// TODO(B): complex signature may need flattening
int rl_GetGlyphIndex(Font font, int codepoint);
// TODO(B): complex signature may need flattening
GlyphInfo rl_GetGlyphInfo(Font font, int codepoint);
// TODO(B): complex signature may need flattening
Rectangle rl_GetImageAlphaBorder(Image image, float threshold);
// TODO(B): complex signature may need flattening
Color rl_GetImageColor(Image image, int x, int y);
const char * rl_GetKeyName(int key);
int rl_GetKeyPressed(void);
float rl_GetMasterVolume(void);
// TODO(B): complex signature may need flattening
BoundingBox rl_GetMeshBoundingBox(Mesh mesh);
// TODO(B): complex signature may need flattening
BoundingBox rl_GetModelBoundingBox(Model model);
int rl_GetMonitorCount(void);
int rl_GetMonitorHeight(int monitor);
const char * rl_GetMonitorName(int monitor);
int rl_GetMonitorPhysicalHeight(int monitor);
int rl_GetMonitorPhysicalWidth(int monitor);
// TODO(B): complex signature may need flattening
Vector2 rl_GetMonitorPosition(int monitor);
int rl_GetMonitorRefreshRate(int monitor);
int rl_GetMonitorWidth(int monitor);
// TODO(B): complex signature may need flattening
Vector2 rl_GetMouseDelta(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetMousePosition(void);
float rl_GetMouseWheelMove(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetMouseWheelMoveV(void);
int rl_GetMouseX(void);
int rl_GetMouseY(void);
// TODO(B): complex signature may need flattening
float rl_GetMusicTimeLength(Music music);
// TODO(B): complex signature may need flattening
float rl_GetMusicTimePlayed(Music music);
// TODO(C): complex signature may need flattening
Color rl_GetPixelColor(void *srcPtr, int format);
int rl_GetPixelDataSize(int width, int height, int format);
const char * rl_GetPrevDirectoryPath(const char *dirPath);
int rl_GetRandomValue(int min, int max);
// TODO(B): complex signature may need flattening
RayCollision rl_GetRayCollisionBox(Ray ray, BoundingBox box);
// TODO(B): complex signature may need flattening
RayCollision rl_GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);
// TODO(B): complex signature may need flattening
RayCollision rl_GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);
// TODO(B): complex signature may need flattening
RayCollision rl_GetRayCollisionSphere(Ray ray, Vector3 center, float radius);
// TODO(B): complex signature may need flattening
RayCollision rl_GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
int rl_GetRenderHeight(void);
int rl_GetRenderWidth(void);
int rl_GetScreenHeight(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetScreenToWorld2D(Vector2 position, Camera2D camera);
// TODO(B): complex signature may need flattening
Ray rl_GetScreenToWorldRay(Vector2 position, Camera camera);
// TODO(B): complex signature may need flattening
Ray rl_GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height);
int rl_GetScreenWidth(void);
// TODO(B): complex signature may need flattening
int rl_GetShaderLocation(Shader shader, const char *uniformName);
// TODO(B): complex signature may need flattening
int rl_GetShaderLocationAttrib(Shader shader, const char *attribName);
// TODO(B): complex signature may need flattening
Texture2D rl_GetShapesTexture(void);
// TODO(B): complex signature may need flattening
Rectangle rl_GetShapesTextureRectangle(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
// TODO(B): complex signature may need flattening
Vector2 rl_GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t);
// TODO(B): complex signature may need flattening
Vector2 rl_GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t);
// TODO(B): complex signature may need flattening
Vector2 rl_GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
// TODO(B): complex signature may need flattening
Vector2 rl_GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t);
char * rl_GetTextBetween(const char *text, const char *begin, const char *end);
double rl_GetTime(void);
int rl_GetTouchPointCount(void);
int rl_GetTouchPointId(int index);
// TODO(B): complex signature may need flattening
Vector2 rl_GetTouchPosition(int index);
int rl_GetTouchX(void);
int rl_GetTouchY(void);
// TODO(B): complex signature may need flattening
void * rl_GetWindowHandle(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetWindowPosition(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetWindowScaleDPI(void);
const char * rl_GetWorkingDirectory(void);
// TODO(B): complex signature may need flattening
Vector2 rl_GetWorldToScreen(Vector3 position, Camera camera);
// TODO(B): complex signature may need flattening
Vector2 rl_GetWorldToScreen2D(Vector2 position, Camera2D camera);
// TODO(B): complex signature may need flattening
Vector2 rl_GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height);
void rl_HideCursor(void);
// TODO(C): complex signature may need flattening
void rl_ImageAlphaClear(Image *image, Color color, float threshold);
// TODO(C): complex signature may need flattening
void rl_ImageAlphaCrop(Image *image, float threshold);
// TODO(C): complex signature may need flattening
void rl_ImageAlphaMask(Image *image, Image alphaMask);
// TODO(C): complex signature may need flattening
void rl_ImageAlphaPremultiply(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageBlurGaussian(Image *image, int blurSize);
// TODO(C): complex signature may need flattening
void rl_ImageClearBackground(Image *dst, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageColorBrightness(Image *image, int brightness);
// TODO(C): complex signature may need flattening
void rl_ImageColorContrast(Image *image, float contrast);
// TODO(C): complex signature may need flattening
void rl_ImageColorGrayscale(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageColorInvert(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageColorReplace(Image *image, Color color, Color replace);
// TODO(C): complex signature may need flattening
void rl_ImageColorTint(Image *image, Color color);
// TODO(B): complex signature may need flattening
Image rl_ImageCopy(Image image);
// TODO(C): complex signature may need flattening
void rl_ImageCrop(Image *image, Rectangle crop);
// TODO(C): complex signature may need flattening
void rl_ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);
// TODO(C): complex signature may need flattening
void rl_ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);
// TODO(C): complex signature may need flattening
void rl_ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawCircleLines(Image *dst, int centerX, int centerY, int radius, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawCircleLinesV(Image *dst, Vector2 center, int radius, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawLineEx(Image *dst, Vector2 start, Vector2 end, int thick, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawPixel(Image *dst, int posX, int posY, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawPixelV(Image *dst, Vector2 position, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTriangle(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTriangleEx(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTriangleFan(Image *dst, const Vector2 *points, int pointCount, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTriangleLines(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageDrawTriangleStrip(Image *dst, const Vector2 *points, int pointCount, Color color);
// TODO(C): complex signature may need flattening
void rl_ImageFlipHorizontal(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageFlipVertical(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageFormat(Image *image, int newFormat);
// TODO(B): complex signature may need flattening
Image rl_ImageFromChannel(Image image, int selectedChannel);
// TODO(B): complex signature may need flattening
Image rl_ImageFromImage(Image image, Rectangle rec);
// TODO(C): complex signature may need flattening
void rl_ImageKernelConvolution(Image *image, const float *kernel, int kernelSize);
// TODO(C): complex signature may need flattening
void rl_ImageMipmaps(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageResize(Image *image, int newWidth, int newHeight);
// TODO(C): complex signature may need flattening
void rl_ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);
// TODO(C): complex signature may need flattening
void rl_ImageResizeNN(Image *image, int newWidth, int newHeight);
// TODO(C): complex signature may need flattening
void rl_ImageRotate(Image *image, int degrees);
// TODO(C): complex signature may need flattening
void rl_ImageRotateCCW(Image *image);
// TODO(C): complex signature may need flattening
void rl_ImageRotateCW(Image *image);
// TODO(B): complex signature may need flattening
Image rl_ImageText(const char *text, int fontSize, Color color);
// TODO(B): complex signature may need flattening
Image rl_ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);
// TODO(C): complex signature may need flattening
void rl_ImageToPOT(Image *image, Color fill);
void rl_InitAudioDevice(void);
void rl_InitWindow(int width, int height, const char *title);
// TODO(B): complex signature may need flattening
bool rl_IsAudioDeviceReady(void);
// TODO(B): complex signature may need flattening
bool rl_IsAudioStreamPlaying(AudioStream stream);
// TODO(B): complex signature may need flattening
bool rl_IsAudioStreamProcessed(AudioStream stream);
// TODO(B): complex signature may need flattening
bool rl_IsAudioStreamValid(AudioStream stream);
// TODO(B): complex signature may need flattening
bool rl_IsCursorHidden(void);
// TODO(B): complex signature may need flattening
bool rl_IsCursorOnScreen(void);
// TODO(B): complex signature may need flattening
bool rl_IsFileDropped(void);
// TODO(B): complex signature may need flattening
bool rl_IsFileExtension(const char *fileName, const char *ext);
// TODO(B): complex signature may need flattening
bool rl_IsFileNameValid(const char *fileName);
// TODO(B): complex signature may need flattening
bool rl_IsFontValid(Font font);
// TODO(B): complex signature may need flattening
bool rl_IsGamepadAvailable(int gamepad);
// TODO(B): complex signature may need flattening
bool rl_IsGamepadButtonDown(int gamepad, int button);
// TODO(B): complex signature may need flattening
bool rl_IsGamepadButtonPressed(int gamepad, int button);
// TODO(B): complex signature may need flattening
bool rl_IsGamepadButtonReleased(int gamepad, int button);
// TODO(B): complex signature may need flattening
bool rl_IsGamepadButtonUp(int gamepad, int button);
// TODO(B): complex signature may need flattening
bool rl_IsGestureDetected(unsigned int gesture);
// TODO(B): complex signature may need flattening
bool rl_IsImageValid(Image image);
// TODO(B): complex signature may need flattening
bool rl_IsKeyDown(int key);
// TODO(B): complex signature may need flattening
bool rl_IsKeyPressed(int key);
// TODO(B): complex signature may need flattening
bool rl_IsKeyPressedRepeat(int key);
// TODO(B): complex signature may need flattening
bool rl_IsKeyReleased(int key);
// TODO(B): complex signature may need flattening
bool rl_IsKeyUp(int key);
// TODO(B): complex signature may need flattening
bool rl_IsMaterialValid(Material material);
// TODO(B): complex signature may need flattening
bool rl_IsModelAnimationValid(Model model, ModelAnimation anim);
// TODO(B): complex signature may need flattening
bool rl_IsModelValid(Model model);
// TODO(B): complex signature may need flattening
bool rl_IsMouseButtonDown(int button);
// TODO(B): complex signature may need flattening
bool rl_IsMouseButtonPressed(int button);
// TODO(B): complex signature may need flattening
bool rl_IsMouseButtonReleased(int button);
// TODO(B): complex signature may need flattening
bool rl_IsMouseButtonUp(int button);
// TODO(B): complex signature may need flattening
bool rl_IsMusicStreamPlaying(Music music);
// TODO(B): complex signature may need flattening
bool rl_IsMusicValid(Music music);
// TODO(B): complex signature may need flattening
bool rl_IsPathFile(const char *path);
// TODO(B): complex signature may need flattening
bool rl_IsRenderTextureValid(RenderTexture2D target);
// TODO(B): complex signature may need flattening
bool rl_IsShaderValid(Shader shader);
// TODO(B): complex signature may need flattening
bool rl_IsSoundPlaying(Sound sound);
// TODO(B): complex signature may need flattening
bool rl_IsSoundValid(Sound sound);
// TODO(B): complex signature may need flattening
bool rl_IsTextureValid(Texture2D texture);
// TODO(B): complex signature may need flattening
bool rl_IsWaveValid(Wave wave);
// TODO(B): complex signature may need flattening
bool rl_IsWindowFocused(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowFullscreen(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowHidden(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowMaximized(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowMinimized(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowReady(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowResized(void);
// TODO(B): complex signature may need flattening
bool rl_IsWindowState(unsigned int flag);
// TODO(B): complex signature may need flattening
AudioStream rl_LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels);
// TODO(B): complex signature may need flattening
AutomationEventList rl_LoadAutomationEventList(const char *fileName);
// TODO(C): complex signature may need flattening
int * rl_LoadCodepoints(const char *text, int *count);
// TODO(B): complex signature may need flattening
FilePathList rl_LoadDirectoryFiles(const char *dirPath);
// TODO(B): complex signature may need flattening
FilePathList rl_LoadDirectoryFilesEx(const char *basePath, const char *filter, bool scanSubdirs);
// TODO(B): complex signature may need flattening
FilePathList rl_LoadDroppedFiles(void);
// TODO(C): complex signature may need flattening
unsigned char * rl_LoadFileData(const char *fileName, int *dataSize);
char * rl_LoadFileText(const char *fileName);
// TODO(B): complex signature may need flattening
Font rl_LoadFont(const char *fileName);
// TODO(C): complex signature may need flattening
GlyphInfo * rl_LoadFontData(const unsigned char *fileData, int dataSize, int fontSize, const int *codepoints, int codepointCount, int type, int *glyphCount);
// TODO(C): complex signature may need flattening
Font rl_LoadFontEx(const char *fileName, int fontSize, const int *codepoints, int codepointCount);
// TODO(B): complex signature may need flattening
Font rl_LoadFontFromImage(Image image, Color key, int firstChar);
// TODO(C): complex signature may need flattening
Font rl_LoadFontFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, const int *codepoints, int codepointCount);
// TODO(B): complex signature may need flattening
Image rl_LoadImage(const char *fileName);
// TODO(C): complex signature may need flattening
Image rl_LoadImageAnim(const char *fileName, int *frames);
// TODO(C): complex signature may need flattening
Image rl_LoadImageAnimFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int *frames);
// TODO(B): complex signature may need flattening
Color * rl_LoadImageColors(Image image);
// TODO(C): complex signature may need flattening
Image rl_LoadImageFromMemory(const char *fileType, const unsigned char *fileData, int dataSize);
// TODO(B): complex signature may need flattening
Image rl_LoadImageFromScreen(void);
// TODO(B): complex signature may need flattening
Image rl_LoadImageFromTexture(Texture2D texture);
// TODO(C): complex signature may need flattening
Color * rl_LoadImagePalette(Image image, int maxPaletteSize, int *colorCount);
// TODO(B): complex signature may need flattening
Image rl_LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);
// TODO(B): complex signature may need flattening
Material rl_LoadMaterialDefault(void);
// TODO(C): complex signature may need flattening
Material * rl_LoadMaterials(const char *fileName, int *materialCount);
// TODO(B): complex signature may need flattening
Model rl_LoadModel(const char *fileName);
// TODO(C): complex signature may need flattening
ModelAnimation * rl_LoadModelAnimations(const char *fileName, int *animCount);
// TODO(B): complex signature may need flattening
Model rl_LoadModelFromMesh(Mesh mesh);
// TODO(B): complex signature may need flattening
Music rl_LoadMusicStream(const char *fileName);
// TODO(C): complex signature may need flattening
Music rl_LoadMusicStreamFromMemory(const char *fileType, const unsigned char *data, int dataSize);
// TODO(B): complex signature may need flattening
int * rl_LoadRandomSequence(unsigned int count, int min, int max);
// TODO(B): complex signature may need flattening
RenderTexture2D rl_LoadRenderTexture(int width, int height);
// TODO(B): complex signature may need flattening
Shader rl_LoadShader(const char *vsFileName, const char *fsFileName);
// TODO(B): complex signature may need flattening
Shader rl_LoadShaderFromMemory(const char *vsCode, const char *fsCode);
// TODO(B): complex signature may need flattening
Sound rl_LoadSound(const char *fileName);
// TODO(B): complex signature may need flattening
Sound rl_LoadSoundAlias(Sound source);
// TODO(B): complex signature may need flattening
Sound rl_LoadSoundFromWave(Wave wave);
// TODO(C): complex signature may need flattening
char ** rl_LoadTextLines(const char *text, int *count);
// TODO(B): complex signature may need flattening
Texture2D rl_LoadTexture(const char *fileName);
// TODO(B): complex signature may need flattening
TextureCubemap rl_LoadTextureCubemap(Image image, int layout);
// TODO(B): complex signature may need flattening
Texture2D rl_LoadTextureFromImage(Image image);
// TODO(C): complex signature may need flattening
char * rl_LoadUTF8(const int *codepoints, int length);
// TODO(B): complex signature may need flattening
VrStereoConfig rl_LoadVrStereoConfig(VrDeviceInfo device);
// TODO(B): complex signature may need flattening
Wave rl_LoadWave(const char *fileName);
// TODO(C): complex signature may need flattening
Wave rl_LoadWaveFromMemory(const char *fileType, const unsigned char *fileData, int dataSize);
// TODO(B): complex signature may need flattening
float * rl_LoadWaveSamples(Wave wave);
int rl_MakeDirectory(const char *dirPath);
void rl_MaximizeWindow(void);
int rl_MeasureText(const char *text, int fontSize);
// TODO(B): complex signature may need flattening
Vector2 rl_MeasureTextEx(Font font, const char *text, float fontSize, float spacing);
// TODO(B): complex signature may need flattening
void * rl_MemAlloc(unsigned int size);
// TODO(C): complex signature may need flattening
void rl_MemFree(void *ptr);
// TODO(C): complex signature may need flattening
void * rl_MemRealloc(void *ptr, unsigned int size);
void rl_MinimizeWindow(void);
void rl_OpenURL(const char *url);
// TODO(B): complex signature may need flattening
void rl_PauseAudioStream(AudioStream stream);
// TODO(B): complex signature may need flattening
void rl_PauseMusicStream(Music music);
// TODO(B): complex signature may need flattening
void rl_PauseSound(Sound sound);
// TODO(B): complex signature may need flattening
void rl_PlayAudioStream(AudioStream stream);
// TODO(B): complex signature may need flattening
void rl_PlayAutomationEvent(AutomationEvent event);
// TODO(B): complex signature may need flattening
void rl_PlayMusicStream(Music music);
// TODO(B): complex signature may need flattening
void rl_PlaySound(Sound sound);
void rl_PollInputEvents(void);
void rl_RestoreWindow(void);
// TODO(B): complex signature may need flattening
void rl_ResumeAudioStream(AudioStream stream);
// TODO(B): complex signature may need flattening
void rl_ResumeMusicStream(Music music);
// TODO(B): complex signature may need flattening
void rl_ResumeSound(Sound sound);
// TODO(C): complex signature may need flattening
bool rl_SaveFileData(const char *fileName, void *data, int dataSize);
// TODO(B): complex signature may need flattening
bool rl_SaveFileText(const char *fileName, const char *text);
// TODO(B): complex signature may need flattening
void rl_SeekMusicStream(Music music, float position);
void rl_SetAudioStreamBufferSizeDefault(int size);
// TODO(D): complex signature may need flattening
void rl_SetAudioStreamCallback(AudioStream stream, AudioCallback callback);
// TODO(B): complex signature may need flattening
void rl_SetAudioStreamPan(AudioStream stream, float pan);
// TODO(B): complex signature may need flattening
void rl_SetAudioStreamPitch(AudioStream stream, float pitch);
// TODO(B): complex signature may need flattening
void rl_SetAudioStreamVolume(AudioStream stream, float volume);
void rl_SetAutomationEventBaseFrame(int frame);
// TODO(C): complex signature may need flattening
void rl_SetAutomationEventList(AutomationEventList *list);
void rl_SetClipboardText(const char *text);
void rl_SetConfigFlags(unsigned int flags);
void rl_SetExitKey(int key);
int rl_SetGamepadMappings(const char *mappings);
void rl_SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration);
void rl_SetGesturesEnabled(unsigned int flags);
// TODO(D): complex signature may need flattening
void rl_SetLoadFileDataCallback(LoadFileDataCallback callback);
// TODO(D): complex signature may need flattening
void rl_SetLoadFileTextCallback(LoadFileTextCallback callback);
void rl_SetMasterVolume(float volume);
// TODO(C): complex signature may need flattening
void rl_SetMaterialTexture(Material *material, int mapType, Texture2D texture);
// TODO(C): complex signature may need flattening
void rl_SetModelMeshMaterial(Model *model, int meshId, int materialId);
void rl_SetMouseCursor(int cursor);
void rl_SetMouseOffset(int offsetX, int offsetY);
void rl_SetMousePosition(int x, int y);
void rl_SetMouseScale(float scaleX, float scaleY);
// TODO(B): complex signature may need flattening
void rl_SetMusicPan(Music music, float pan);
// TODO(B): complex signature may need flattening
void rl_SetMusicPitch(Music music, float pitch);
// TODO(B): complex signature may need flattening
void rl_SetMusicVolume(Music music, float volume);
// TODO(C): complex signature may need flattening
void rl_SetPixelColor(void *dstPtr, Color color, int format);
void rl_SetRandomSeed(unsigned int seed);
// TODO(D): complex signature may need flattening
void rl_SetSaveFileDataCallback(SaveFileDataCallback callback);
// TODO(D): complex signature may need flattening
void rl_SetSaveFileTextCallback(SaveFileTextCallback callback);
// TODO(C): complex signature may need flattening
void rl_SetShaderValue(Shader shader, int locIndex, const void *value, int uniformType);
// TODO(B): complex signature may need flattening
void rl_SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat);
// TODO(B): complex signature may need flattening
void rl_SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture);
// TODO(C): complex signature may need flattening
void rl_SetShaderValueV(Shader shader, int locIndex, const void *value, int uniformType, int count);
// TODO(B): complex signature may need flattening
void rl_SetShapesTexture(Texture2D texture, Rectangle source);
// TODO(B): complex signature may need flattening
void rl_SetSoundPan(Sound sound, float pan);
// TODO(B): complex signature may need flattening
void rl_SetSoundPitch(Sound sound, float pitch);
// TODO(B): complex signature may need flattening
void rl_SetSoundVolume(Sound sound, float volume);
void rl_SetTargetFPS(int fps);
void rl_SetTextLineSpacing(int spacing);
// TODO(B): complex signature may need flattening
void rl_SetTextureFilter(Texture2D texture, int filter);
// TODO(B): complex signature may need flattening
void rl_SetTextureWrap(Texture2D texture, int wrap);
// TODO(D): complex signature may need flattening
void rl_SetTraceLogCallback(TraceLogCallback callback);
void rl_SetTraceLogLevel(int logLevel);
void rl_SetWindowFocused(void);
// TODO(B): complex signature may need flattening
void rl_SetWindowIcon(Image image);
// TODO(C): complex signature may need flattening
void rl_SetWindowIcons(Image *images, int count);
void rl_SetWindowMaxSize(int width, int height);
void rl_SetWindowMinSize(int width, int height);
void rl_SetWindowMonitor(int monitor);
void rl_SetWindowOpacity(float opacity);
void rl_SetWindowPosition(int x, int y);
void rl_SetWindowSize(int width, int height);
void rl_SetWindowState(unsigned int flags);
void rl_SetWindowTitle(const char *title);
void rl_ShowCursor(void);
void rl_StartAutomationEventRecording(void);
// TODO(B): complex signature may need flattening
void rl_StopAudioStream(AudioStream stream);
void rl_StopAutomationEventRecording(void);
// TODO(B): complex signature may need flattening
void rl_StopMusicStream(Music music);
// TODO(B): complex signature may need flattening
void rl_StopSound(Sound sound);
void rl_SwapScreenBuffer(void);
void rl_TakeScreenshot(const char *fileName);
// TODO(C): complex signature may need flattening
void rl_TextAppend(char *text, const char *append, int *position);
int rl_TextCopy(char *dst, const char *src);
int rl_TextFindIndex(const char *text, const char *search);
// TODO(D): complex signature may need flattening
const char * rl_TextFormat(const char *text, ...);
char * rl_TextInsert(const char *text, const char *insert, int position);
// TODO(B): complex signature may need flattening
bool rl_TextIsEqual(const char *text1, const char *text2);
// TODO(C): complex signature may need flattening
char * rl_TextJoin(char **textList, int count, const char *delimiter);
unsigned int rl_TextLength(const char *text);
const char * rl_TextRemoveSpaces(const char *text);
char * rl_TextReplace(const char *text, const char *search, const char *replacement);
char * rl_TextReplaceBetween(const char *text, const char *begin, const char *end, const char *replacement);
// TODO(C): complex signature may need flattening
char ** rl_TextSplit(const char *text, char delimiter, int *count);
const char * rl_TextSubtext(const char *text, int position, int length);
char * rl_TextToCamel(const char *text);
float rl_TextToFloat(const char *text);
int rl_TextToInteger(const char *text);
char * rl_TextToLower(const char *text);
char * rl_TextToPascal(const char *text);
char * rl_TextToSnake(const char *text);
char * rl_TextToUpper(const char *text);
void rl_ToggleBorderlessWindowed(void);
void rl_ToggleFullscreen(void);
// TODO(D): complex signature may need flattening
void rl_TraceLog(int logLevel, const char *text, ...);
// TODO(B): complex signature may need flattening
void rl_UnloadAudioStream(AudioStream stream);
// TODO(B): complex signature may need flattening
void rl_UnloadAutomationEventList(AutomationEventList list);
// TODO(C): complex signature may need flattening
void rl_UnloadCodepoints(int *codepoints);
// TODO(B): complex signature may need flattening
void rl_UnloadDirectoryFiles(FilePathList files);
// TODO(B): complex signature may need flattening
void rl_UnloadDroppedFiles(FilePathList files);
// TODO(C): complex signature may need flattening
void rl_UnloadFileData(unsigned char *data);
void rl_UnloadFileText(char *text);
// TODO(B): complex signature may need flattening
void rl_UnloadFont(Font font);
// TODO(C): complex signature may need flattening
void rl_UnloadFontData(GlyphInfo *glyphs, int glyphCount);
// TODO(B): complex signature may need flattening
void rl_UnloadImage(Image image);
// TODO(C): complex signature may need flattening
void rl_UnloadImageColors(Color *colors);
// TODO(C): complex signature may need flattening
void rl_UnloadImagePalette(Color *colors);
// TODO(B): complex signature may need flattening
void rl_UnloadMaterial(Material material);
// TODO(B): complex signature may need flattening
void rl_UnloadMesh(Mesh mesh);
// TODO(B): complex signature may need flattening
void rl_UnloadModel(Model model);
// TODO(B): complex signature may need flattening
void rl_UnloadModelAnimation(ModelAnimation anim);
// TODO(C): complex signature may need flattening
void rl_UnloadModelAnimations(ModelAnimation *animations, int animCount);
// TODO(B): complex signature may need flattening
void rl_UnloadMusicStream(Music music);
// TODO(C): complex signature may need flattening
void rl_UnloadRandomSequence(int *sequence);
// TODO(B): complex signature may need flattening
void rl_UnloadRenderTexture(RenderTexture2D target);
// TODO(B): complex signature may need flattening
void rl_UnloadShader(Shader shader);
// TODO(B): complex signature may need flattening
void rl_UnloadSound(Sound sound);
// TODO(B): complex signature may need flattening
void rl_UnloadSoundAlias(Sound alias);
// TODO(C): complex signature may need flattening
void rl_UnloadTextLines(char **text, int lineCount);
// TODO(B): complex signature may need flattening
void rl_UnloadTexture(Texture2D texture);
void rl_UnloadUTF8(char *text);
// TODO(B): complex signature may need flattening
void rl_UnloadVrStereoConfig(VrStereoConfig config);
// TODO(B): complex signature may need flattening
void rl_UnloadWave(Wave wave);
// TODO(C): complex signature may need flattening
void rl_UnloadWaveSamples(float *samples);
// TODO(C): complex signature may need flattening
void rl_UpdateAudioStream(AudioStream stream, const void *data, int frameCount);
// TODO(C): complex signature may need flattening
void rl_UpdateCamera(Camera *camera, int mode);
// TODO(C): complex signature may need flattening
void rl_UpdateCameraPro(Camera *camera, Vector3 movement, Vector3 rotation, float zoom);
// TODO(C): complex signature may need flattening
void rl_UpdateMeshBuffer(Mesh mesh, int index, const void *data, int dataSize, int offset);
// TODO(B): complex signature may need flattening
void rl_UpdateModelAnimation(Model model, ModelAnimation anim, int frame);
// TODO(B): complex signature may need flattening
void rl_UpdateModelAnimationBones(Model model, ModelAnimation anim, int frame);
// TODO(B): complex signature may need flattening
void rl_UpdateMusicStream(Music music);
// TODO(C): complex signature may need flattening
void rl_UpdateSound(Sound sound, const void *data, int sampleCount);
// TODO(C): complex signature may need flattening
void rl_UpdateTexture(Texture2D texture, const void *pixels);
// TODO(C): complex signature may need flattening
void rl_UpdateTextureRec(Texture2D texture, Rectangle rec, const void *pixels);
// TODO(C): complex signature may need flattening
void rl_UploadMesh(Mesh *mesh, bool dynamic);
void rl_WaitTime(double seconds);
// TODO(B): complex signature may need flattening
Wave rl_WaveCopy(Wave wave);
// TODO(C): complex signature may need flattening
void rl_WaveCrop(Wave *wave, int initFrame, int finalFrame);
// TODO(C): complex signature may need flattening
void rl_WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels);
// TODO(B): complex signature may need flattening
bool rl_WindowShouldClose(void);

#ifdef __cplusplus
}
#endif

#endif
