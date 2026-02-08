#include "raylib_shim.h"

void rl_AttachAudioMixedProcessor(AudioCallback processor)
{
    // TODO: implement wrapper for AttachAudioMixedProcessor
    (void)processor;
    // TODO: class D requires manual handling
    return;
}

void rl_AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor)
{
    // TODO: implement wrapper for AttachAudioStreamProcessor
    (void)stream;
    (void)processor;
    // TODO: class D requires manual handling
    return;
}

void rl_BeginBlendMode(int mode)
{
    // TODO: implement wrapper for BeginBlendMode
    (void)mode;
    return;
}

void rl_BeginDrawing(void)
{
    // TODO: implement wrapper for BeginDrawing
    return;
}

void rl_BeginMode2D(Camera2D camera)
{
    // TODO: implement wrapper for BeginMode2D
    (void)camera;
    // TODO: class B requires manual handling
    return;
}

void rl_BeginMode3D(Camera3D camera)
{
    // TODO: implement wrapper for BeginMode3D
    (void)camera;
    // TODO: class B requires manual handling
    return;
}

void rl_BeginScissorMode(int x, int y, int width, int height)
{
    // TODO: implement wrapper for BeginScissorMode
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    return;
}

void rl_BeginShaderMode(Shader shader)
{
    // TODO: implement wrapper for BeginShaderMode
    (void)shader;
    // TODO: class B requires manual handling
    return;
}

void rl_BeginTextureMode(RenderTexture2D target)
{
    // TODO: implement wrapper for BeginTextureMode
    (void)target;
    // TODO: class B requires manual handling
    return;
}

void rl_BeginVrStereoMode(VrStereoConfig config)
{
    // TODO: implement wrapper for BeginVrStereoMode
    (void)config;
    // TODO: class B requires manual handling
    return;
}

bool rl_ChangeDirectory(const char *dirPath)
{
    // TODO: implement wrapper for ChangeDirectory
    (void)dirPath;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius)
{
    // TODO: implement wrapper for CheckCollisionBoxSphere
    (void)box;
    (void)center;
    (void)radius;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionBoxes(BoundingBox box1, BoundingBox box2)
{
    // TODO: implement wrapper for CheckCollisionBoxes
    (void)box1;
    (void)box2;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2)
{
    // TODO: implement wrapper for CheckCollisionCircleLine
    (void)center;
    (void)radius;
    (void)p1;
    (void)p2;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
{
    // TODO: implement wrapper for CheckCollisionCircleRec
    (void)center;
    (void)radius;
    (void)rec;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2)
{
    // TODO: implement wrapper for CheckCollisionCircles
    (void)center1;
    (void)radius1;
    (void)center2;
    (void)radius2;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint)
{
    // TODO: implement wrapper for CheckCollisionLines
    (void)startPos1;
    (void)endPos1;
    (void)startPos2;
    (void)endPos2;
    (void)collisionPoint;
    // TODO: class C requires manual handling
    return false;
}

bool rl_CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius)
{
    // TODO: implement wrapper for CheckCollisionPointCircle
    (void)point;
    (void)center;
    (void)radius;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold)
{
    // TODO: implement wrapper for CheckCollisionPointLine
    (void)point;
    (void)p1;
    (void)p2;
    (void)threshold;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionPointPoly(Vector2 point, const Vector2 *points, int pointCount)
{
    // TODO: implement wrapper for CheckCollisionPointPoly
    (void)point;
    (void)points;
    (void)pointCount;
    // TODO: class C requires manual handling
    return false;
}

bool rl_CheckCollisionPointRec(Vector2 point, Rectangle rec)
{
    // TODO: implement wrapper for CheckCollisionPointRec
    (void)point;
    (void)rec;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3)
{
    // TODO: implement wrapper for CheckCollisionPointTriangle
    (void)point;
    (void)p1;
    (void)p2;
    (void)p3;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionRecs(Rectangle rec1, Rectangle rec2)
{
    // TODO: implement wrapper for CheckCollisionRecs
    (void)rec1;
    (void)rec2;
    // TODO: class B requires manual handling
    return false;
}

bool rl_CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2)
{
    // TODO: implement wrapper for CheckCollisionSpheres
    (void)center1;
    (void)radius1;
    (void)center2;
    (void)radius2;
    // TODO: class B requires manual handling
    return false;
}

void rl_ClearBackground(Color color)
{
    // TODO: implement wrapper for ClearBackground
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_ClearWindowState(unsigned int flags)
{
    // TODO: implement wrapper for ClearWindowState
    (void)flags;
    return;
}

void rl_CloseAudioDevice(void)
{
    // TODO: implement wrapper for CloseAudioDevice
    return;
}

void rl_CloseWindow(void)
{
    // TODO: implement wrapper for CloseWindow
    return;
}

const char * rl_CodepointToUTF8(int codepoint, int *utf8Size)
{
    // TODO: implement wrapper for CodepointToUTF8
    (void)codepoint;
    (void)utf8Size;
    // TODO: class C requires manual handling
    return NULL;
}

Color rl_ColorAlpha(Color color, float alpha)
{
    // TODO: implement wrapper for ColorAlpha
    (void)color;
    (void)alpha;
    // TODO: class B requires manual handling
    return (Color){0};
}

Color rl_ColorAlphaBlend(Color dst, Color src, Color tint)
{
    // TODO: implement wrapper for ColorAlphaBlend
    (void)dst;
    (void)src;
    (void)tint;
    // TODO: class B requires manual handling
    return (Color){0};
}

Color rl_ColorBrightness(Color color, float factor)
{
    // TODO: implement wrapper for ColorBrightness
    (void)color;
    (void)factor;
    // TODO: class B requires manual handling
    return (Color){0};
}

Color rl_ColorContrast(Color color, float contrast)
{
    // TODO: implement wrapper for ColorContrast
    (void)color;
    (void)contrast;
    // TODO: class B requires manual handling
    return (Color){0};
}

Color rl_ColorFromHSV(float hue, float saturation, float value)
{
    // TODO: implement wrapper for ColorFromHSV
    (void)hue;
    (void)saturation;
    (void)value;
    // TODO: class B requires manual handling
    return (Color){0};
}

Color rl_ColorFromNormalized(Vector4 normalized)
{
    // TODO: implement wrapper for ColorFromNormalized
    (void)normalized;
    // TODO: class B requires manual handling
    return (Color){0};
}

bool rl_ColorIsEqual(Color col1, Color col2)
{
    // TODO: implement wrapper for ColorIsEqual
    (void)col1;
    (void)col2;
    // TODO: class B requires manual handling
    return false;
}

Color rl_ColorLerp(Color color1, Color color2, float factor)
{
    // TODO: implement wrapper for ColorLerp
    (void)color1;
    (void)color2;
    (void)factor;
    // TODO: class B requires manual handling
    return (Color){0};
}

Vector4 rl_ColorNormalize(Color color)
{
    // TODO: implement wrapper for ColorNormalize
    (void)color;
    // TODO: class B requires manual handling
    return (Vector4){0};
}

Color rl_ColorTint(Color color, Color tint)
{
    // TODO: implement wrapper for ColorTint
    (void)color;
    (void)tint;
    // TODO: class B requires manual handling
    return (Color){0};
}

Vector3 rl_ColorToHSV(Color color)
{
    // TODO: implement wrapper for ColorToHSV
    (void)color;
    // TODO: class B requires manual handling
    return (Vector3){0};
}

int rl_ColorToInt(Color color)
{
    // TODO: implement wrapper for ColorToInt
    (void)color;
    // TODO: class B requires manual handling
    return 0;
}

unsigned char * rl_CompressData(const unsigned char *data, int dataSize, int *compDataSize)
{
    // TODO: implement wrapper for CompressData
    (void)data;
    (void)dataSize;
    (void)compDataSize;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned int rl_ComputeCRC32(unsigned char *data, int dataSize)
{
    // TODO: implement wrapper for ComputeCRC32
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return 0;
}

unsigned int * rl_ComputeMD5(unsigned char *data, int dataSize)
{
    // TODO: implement wrapper for ComputeMD5
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned int * rl_ComputeSHA1(unsigned char *data, int dataSize)
{
    // TODO: implement wrapper for ComputeSHA1
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned int * rl_ComputeSHA256(unsigned char *data, int dataSize)
{
    // TODO: implement wrapper for ComputeSHA256
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned char * rl_DecodeDataBase64(const char *text, int *outputSize)
{
    // TODO: implement wrapper for DecodeDataBase64
    (void)text;
    (void)outputSize;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned char * rl_DecompressData(const unsigned char *compData, int compDataSize, int *dataSize)
{
    // TODO: implement wrapper for DecompressData
    (void)compData;
    (void)compDataSize;
    (void)dataSize;
    // TODO: class C requires manual handling
    return NULL;
}

void rl_DetachAudioMixedProcessor(AudioCallback processor)
{
    // TODO: implement wrapper for DetachAudioMixedProcessor
    (void)processor;
    // TODO: class D requires manual handling
    return;
}

void rl_DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor)
{
    // TODO: implement wrapper for DetachAudioStreamProcessor
    (void)stream;
    (void)processor;
    // TODO: class D requires manual handling
    return;
}

bool rl_DirectoryExists(const char *dirPath)
{
    // TODO: implement wrapper for DirectoryExists
    (void)dirPath;
    // TODO: class B requires manual handling
    return false;
}

void rl_DisableCursor(void)
{
    // TODO: implement wrapper for DisableCursor
    return;
}

void rl_DisableEventWaiting(void)
{
    // TODO: implement wrapper for DisableEventWaiting
    return;
}

void rl_DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint)
{
    // TODO: implement wrapper for DrawBillboard
    (void)camera;
    (void)texture;
    (void)position;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint)
{
    // TODO: implement wrapper for DrawBillboardPro
    (void)camera;
    (void)texture;
    (void)source;
    (void)position;
    (void)up;
    (void)size;
    (void)origin;
    (void)rotation;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint)
{
    // TODO: implement wrapper for DrawBillboardRec
    (void)camera;
    (void)texture;
    (void)source;
    (void)position;
    (void)size;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawBoundingBox(BoundingBox box, Color color)
{
    // TODO: implement wrapper for DrawBoundingBox
    (void)box;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color)
{
    // TODO: implement wrapper for DrawCapsule
    (void)startPos;
    (void)endPos;
    (void)radius;
    (void)slices;
    (void)rings;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color)
{
    // TODO: implement wrapper for DrawCapsuleWires
    (void)startPos;
    (void)endPos;
    (void)radius;
    (void)slices;
    (void)rings;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircle(int centerX, int centerY, float radius, Color color)
{
    // TODO: implement wrapper for DrawCircle
    (void)centerX;
    (void)centerY;
    (void)radius;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color)
{
    // TODO: implement wrapper for DrawCircle3D
    (void)center;
    (void)radius;
    (void)rotationAxis;
    (void)rotationAngle;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer)
{
    // TODO: implement wrapper for DrawCircleGradient
    (void)centerX;
    (void)centerY;
    (void)radius;
    (void)inner;
    (void)outer;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleLines(int centerX, int centerY, float radius, Color color)
{
    // TODO: implement wrapper for DrawCircleLines
    (void)centerX;
    (void)centerY;
    (void)radius;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleLinesV(Vector2 center, float radius, Color color)
{
    // TODO: implement wrapper for DrawCircleLinesV
    (void)center;
    (void)radius;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{
    // TODO: implement wrapper for DrawCircleSector
    (void)center;
    (void)radius;
    (void)startAngle;
    (void)endAngle;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{
    // TODO: implement wrapper for DrawCircleSectorLines
    (void)center;
    (void)radius;
    (void)startAngle;
    (void)endAngle;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCircleV(Vector2 center, float radius, Color color)
{
    // TODO: implement wrapper for DrawCircleV
    (void)center;
    (void)radius;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCube(Vector3 position, float width, float height, float length, Color color)
{
    // TODO: implement wrapper for DrawCube
    (void)position;
    (void)width;
    (void)height;
    (void)length;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCubeV(Vector3 position, Vector3 size, Color color)
{
    // TODO: implement wrapper for DrawCubeV
    (void)position;
    (void)size;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCubeWires(Vector3 position, float width, float height, float length, Color color)
{
    // TODO: implement wrapper for DrawCubeWires
    (void)position;
    (void)width;
    (void)height;
    (void)length;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCubeWiresV(Vector3 position, Vector3 size, Color color)
{
    // TODO: implement wrapper for DrawCubeWiresV
    (void)position;
    (void)size;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{
    // TODO: implement wrapper for DrawCylinder
    (void)position;
    (void)radiusTop;
    (void)radiusBottom;
    (void)height;
    (void)slices;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)
{
    // TODO: implement wrapper for DrawCylinderEx
    (void)startPos;
    (void)endPos;
    (void)startRadius;
    (void)endRadius;
    (void)sides;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{
    // TODO: implement wrapper for DrawCylinderWires
    (void)position;
    (void)radiusTop;
    (void)radiusBottom;
    (void)height;
    (void)slices;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)
{
    // TODO: implement wrapper for DrawCylinderWiresEx
    (void)startPos;
    (void)endPos;
    (void)startRadius;
    (void)endRadius;
    (void)sides;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    // TODO: implement wrapper for DrawEllipse
    (void)centerX;
    (void)centerY;
    (void)radiusH;
    (void)radiusV;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    // TODO: implement wrapper for DrawEllipseLines
    (void)centerX;
    (void)centerY;
    (void)radiusH;
    (void)radiusV;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawEllipseLinesV(Vector2 center, float radiusH, float radiusV, Color color)
{
    // TODO: implement wrapper for DrawEllipseLinesV
    (void)center;
    (void)radiusH;
    (void)radiusV;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawEllipseV(Vector2 center, float radiusH, float radiusV, Color color)
{
    // TODO: implement wrapper for DrawEllipseV
    (void)center;
    (void)radiusH;
    (void)radiusV;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawFPS(int posX, int posY)
{
    // TODO: implement wrapper for DrawFPS
    (void)posX;
    (void)posY;
    return;
}

void rl_DrawGrid(int slices, float spacing)
{
    // TODO: implement wrapper for DrawGrid
    (void)slices;
    (void)spacing;
    return;
}

void rl_DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    // TODO: implement wrapper for DrawLine
    (void)startPosX;
    (void)startPosY;
    (void)endPosX;
    (void)endPosY;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawLine3D(Vector3 startPos, Vector3 endPos, Color color)
{
    // TODO: implement wrapper for DrawLine3D
    (void)startPos;
    (void)endPos;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    // TODO: implement wrapper for DrawLineBezier
    (void)startPos;
    (void)endPos;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawLineDashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color)
{
    // TODO: implement wrapper for DrawLineDashed
    (void)startPos;
    (void)endPos;
    (void)dashSize;
    (void)spaceSize;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    // TODO: implement wrapper for DrawLineEx
    (void)startPos;
    (void)endPos;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawLineStrip(const Vector2 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for DrawLineStrip
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawLineV(Vector2 startPos, Vector2 endPos, Color color)
{
    // TODO: implement wrapper for DrawLineV
    (void)startPos;
    (void)endPos;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawMesh(Mesh mesh, Material material, Matrix transform)
{
    // TODO: implement wrapper for DrawMesh
    (void)mesh;
    (void)material;
    (void)transform;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawMeshInstanced(Mesh mesh, Material material, const Matrix *transforms, int instances)
{
    // TODO: implement wrapper for DrawMeshInstanced
    (void)mesh;
    (void)material;
    (void)transforms;
    (void)instances;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawModel(Model model, Vector3 position, float scale, Color tint)
{
    // TODO: implement wrapper for DrawModel
    (void)model;
    (void)position;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    // TODO: implement wrapper for DrawModelEx
    (void)model;
    (void)position;
    (void)rotationAxis;
    (void)rotationAngle;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawModelPoints(Model model, Vector3 position, float scale, Color tint)
{
    // TODO: implement wrapper for DrawModelPoints
    (void)model;
    (void)position;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawModelPointsEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    // TODO: implement wrapper for DrawModelPointsEx
    (void)model;
    (void)position;
    (void)rotationAxis;
    (void)rotationAngle;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawModelWires(Model model, Vector3 position, float scale, Color tint)
{
    // TODO: implement wrapper for DrawModelWires
    (void)model;
    (void)position;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    // TODO: implement wrapper for DrawModelWiresEx
    (void)model;
    (void)position;
    (void)rotationAxis;
    (void)rotationAngle;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPixel(int posX, int posY, Color color)
{
    // TODO: implement wrapper for DrawPixel
    (void)posX;
    (void)posY;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPixelV(Vector2 position, Color color)
{
    // TODO: implement wrapper for DrawPixelV
    (void)position;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPlane(Vector3 centerPos, Vector2 size, Color color)
{
    // TODO: implement wrapper for DrawPlane
    (void)centerPos;
    (void)size;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPoint3D(Vector3 position, Color color)
{
    // TODO: implement wrapper for DrawPoint3D
    (void)position;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color)
{
    // TODO: implement wrapper for DrawPoly
    (void)center;
    (void)sides;
    (void)radius;
    (void)rotation;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color)
{
    // TODO: implement wrapper for DrawPolyLines
    (void)center;
    (void)sides;
    (void)radius;
    (void)rotation;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color)
{
    // TODO: implement wrapper for DrawPolyLinesEx
    (void)center;
    (void)sides;
    (void)radius;
    (void)rotation;
    (void)lineThick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRay(Ray ray, Color color)
{
    // TODO: implement wrapper for DrawRay
    (void)ray;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangle(int posX, int posY, int width, int height, Color color)
{
    // TODO: implement wrapper for DrawRectangle
    (void)posX;
    (void)posY;
    (void)width;
    (void)height;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color bottomRight, Color topRight)
{
    // TODO: implement wrapper for DrawRectangleGradientEx
    (void)rec;
    (void)topLeft;
    (void)bottomLeft;
    (void)bottomRight;
    (void)topRight;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right)
{
    // TODO: implement wrapper for DrawRectangleGradientH
    (void)posX;
    (void)posY;
    (void)width;
    (void)height;
    (void)left;
    (void)right;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom)
{
    // TODO: implement wrapper for DrawRectangleGradientV
    (void)posX;
    (void)posY;
    (void)width;
    (void)height;
    (void)top;
    (void)bottom;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleLines(int posX, int posY, int width, int height, Color color)
{
    // TODO: implement wrapper for DrawRectangleLines
    (void)posX;
    (void)posY;
    (void)width;
    (void)height;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color)
{
    // TODO: implement wrapper for DrawRectangleLinesEx
    (void)rec;
    (void)lineThick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color)
{
    // TODO: implement wrapper for DrawRectanglePro
    (void)rec;
    (void)origin;
    (void)rotation;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleRec(Rectangle rec, Color color)
{
    // TODO: implement wrapper for DrawRectangleRec
    (void)rec;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color)
{
    // TODO: implement wrapper for DrawRectangleRounded
    (void)rec;
    (void)roundness;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color)
{
    // TODO: implement wrapper for DrawRectangleRoundedLines
    (void)rec;
    (void)roundness;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color)
{
    // TODO: implement wrapper for DrawRectangleRoundedLinesEx
    (void)rec;
    (void)roundness;
    (void)segments;
    (void)lineThick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRectangleV(Vector2 position, Vector2 size, Color color)
{
    // TODO: implement wrapper for DrawRectangleV
    (void)position;
    (void)size;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{
    // TODO: implement wrapper for DrawRing
    (void)center;
    (void)innerRadius;
    (void)outerRadius;
    (void)startAngle;
    (void)endAngle;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{
    // TODO: implement wrapper for DrawRingLines
    (void)center;
    (void)innerRadius;
    (void)outerRadius;
    (void)startAngle;
    (void)endAngle;
    (void)segments;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSphere(Vector3 centerPos, float radius, Color color)
{
    // TODO: implement wrapper for DrawSphere
    (void)centerPos;
    (void)radius;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color)
{
    // TODO: implement wrapper for DrawSphereEx
    (void)centerPos;
    (void)radius;
    (void)rings;
    (void)slices;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color)
{
    // TODO: implement wrapper for DrawSphereWires
    (void)centerPos;
    (void)radius;
    (void)rings;
    (void)slices;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSplineBasis(const Vector2 *points, int pointCount, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineBasis
    (void)points;
    (void)pointCount;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawSplineBezierCubic(const Vector2 *points, int pointCount, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineBezierCubic
    (void)points;
    (void)pointCount;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawSplineBezierQuadratic(const Vector2 *points, int pointCount, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineBezierQuadratic
    (void)points;
    (void)pointCount;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawSplineCatmullRom(const Vector2 *points, int pointCount, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineCatmullRom
    (void)points;
    (void)pointCount;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawSplineLinear(const Vector2 *points, int pointCount, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineLinear
    (void)points;
    (void)pointCount;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineSegmentBasis
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineSegmentBezierCubic
    (void)p1;
    (void)c2;
    (void)c3;
    (void)p4;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineSegmentBezierQuadratic
    (void)p1;
    (void)c2;
    (void)p3;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineSegmentCatmullRom
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color)
{
    // TODO: implement wrapper for DrawSplineSegmentLinear
    (void)p1;
    (void)p2;
    (void)thick;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    // TODO: implement wrapper for DrawText
    (void)text;
    (void)posX;
    (void)posY;
    (void)fontSize;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint)
{
    // TODO: implement wrapper for DrawTextCodepoint
    (void)font;
    (void)codepoint;
    (void)position;
    (void)fontSize;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextCodepoints(Font font, const int *codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint)
{
    // TODO: implement wrapper for DrawTextCodepoints
    (void)font;
    (void)codepoints;
    (void)codepointCount;
    (void)position;
    (void)fontSize;
    (void)spacing;
    (void)tint;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    // TODO: implement wrapper for DrawTextEx
    (void)font;
    (void)text;
    (void)position;
    (void)fontSize;
    (void)spacing;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextPro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
{
    // TODO: implement wrapper for DrawTextPro
    (void)font;
    (void)text;
    (void)position;
    (void)origin;
    (void)rotation;
    (void)fontSize;
    (void)spacing;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTexture(Texture2D texture, int posX, int posY, Color tint)
{
    // TODO: implement wrapper for DrawTexture
    (void)texture;
    (void)posX;
    (void)posY;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    // TODO: implement wrapper for DrawTextureEx
    (void)texture;
    (void)position;
    (void)rotation;
    (void)scale;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    // TODO: implement wrapper for DrawTextureNPatch
    (void)texture;
    (void)nPatchInfo;
    (void)dest;
    (void)origin;
    (void)rotation;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    // TODO: implement wrapper for DrawTexturePro
    (void)texture;
    (void)source;
    (void)dest;
    (void)origin;
    (void)rotation;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint)
{
    // TODO: implement wrapper for DrawTextureRec
    (void)texture;
    (void)source;
    (void)position;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTextureV(Texture2D texture, Vector2 position, Color tint)
{
    // TODO: implement wrapper for DrawTextureV
    (void)texture;
    (void)position;
    (void)tint;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    // TODO: implement wrapper for DrawTriangle
    (void)v1;
    (void)v2;
    (void)v3;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color)
{
    // TODO: implement wrapper for DrawTriangle3D
    (void)v1;
    (void)v2;
    (void)v3;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTriangleFan(const Vector2 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for DrawTriangleFan
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    // TODO: implement wrapper for DrawTriangleLines
    (void)v1;
    (void)v2;
    (void)v3;
    (void)color;
    // TODO: class B requires manual handling
    return;
}

void rl_DrawTriangleStrip(const Vector2 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for DrawTriangleStrip
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_DrawTriangleStrip3D(const Vector3 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for DrawTriangleStrip3D
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_EnableCursor(void)
{
    // TODO: implement wrapper for EnableCursor
    return;
}

void rl_EnableEventWaiting(void)
{
    // TODO: implement wrapper for EnableEventWaiting
    return;
}

char * rl_EncodeDataBase64(const unsigned char *data, int dataSize, int *outputSize)
{
    // TODO: implement wrapper for EncodeDataBase64
    (void)data;
    (void)dataSize;
    (void)outputSize;
    // TODO: class C requires manual handling
    return NULL;
}

void rl_EndBlendMode(void)
{
    // TODO: implement wrapper for EndBlendMode
    return;
}

void rl_EndDrawing(void)
{
    // TODO: implement wrapper for EndDrawing
    return;
}

void rl_EndMode2D(void)
{
    // TODO: implement wrapper for EndMode2D
    return;
}

void rl_EndMode3D(void)
{
    // TODO: implement wrapper for EndMode3D
    return;
}

void rl_EndScissorMode(void)
{
    // TODO: implement wrapper for EndScissorMode
    return;
}

void rl_EndShaderMode(void)
{
    // TODO: implement wrapper for EndShaderMode
    return;
}

void rl_EndTextureMode(void)
{
    // TODO: implement wrapper for EndTextureMode
    return;
}

void rl_EndVrStereoMode(void)
{
    // TODO: implement wrapper for EndVrStereoMode
    return;
}

bool rl_ExportAutomationEventList(AutomationEventList list, const char *fileName)
{
    // TODO: implement wrapper for ExportAutomationEventList
    (void)list;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportDataAsCode(const unsigned char *data, int dataSize, const char *fileName)
{
    // TODO: implement wrapper for ExportDataAsCode
    (void)data;
    (void)dataSize;
    (void)fileName;
    // TODO: class C requires manual handling
    return false;
}

bool rl_ExportFontAsCode(Font font, const char *fileName)
{
    // TODO: implement wrapper for ExportFontAsCode
    (void)font;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportImage(Image image, const char *fileName)
{
    // TODO: implement wrapper for ExportImage
    (void)image;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportImageAsCode(Image image, const char *fileName)
{
    // TODO: implement wrapper for ExportImageAsCode
    (void)image;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

unsigned char * rl_ExportImageToMemory(Image image, const char *fileType, int *fileSize)
{
    // TODO: implement wrapper for ExportImageToMemory
    (void)image;
    (void)fileType;
    (void)fileSize;
    // TODO: class C requires manual handling
    return NULL;
}

bool rl_ExportMesh(Mesh mesh, const char *fileName)
{
    // TODO: implement wrapper for ExportMesh
    (void)mesh;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportMeshAsCode(Mesh mesh, const char *fileName)
{
    // TODO: implement wrapper for ExportMeshAsCode
    (void)mesh;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportWave(Wave wave, const char *fileName)
{
    // TODO: implement wrapper for ExportWave
    (void)wave;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_ExportWaveAsCode(Wave wave, const char *fileName)
{
    // TODO: implement wrapper for ExportWaveAsCode
    (void)wave;
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

Color rl_Fade(Color color, float alpha)
{
    // TODO: implement wrapper for Fade
    (void)color;
    (void)alpha;
    // TODO: class B requires manual handling
    return (Color){0};
}

int rl_FileCopy(const char *srcPath, const char *dstPath)
{
    // TODO: implement wrapper for FileCopy
    (void)srcPath;
    (void)dstPath;
    return 0;
}

bool rl_FileExists(const char *fileName)
{
    // TODO: implement wrapper for FileExists
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

int rl_FileMove(const char *srcPath, const char *dstPath)
{
    // TODO: implement wrapper for FileMove
    (void)srcPath;
    (void)dstPath;
    return 0;
}

int rl_FileRemove(const char *fileName)
{
    // TODO: implement wrapper for FileRemove
    (void)fileName;
    return 0;
}

int rl_FileRename(const char *fileName, const char *fileRename)
{
    // TODO: implement wrapper for FileRename
    (void)fileName;
    (void)fileRename;
    return 0;
}

int rl_FileTextFindIndex(const char *fileName, const char *search)
{
    // TODO: implement wrapper for FileTextFindIndex
    (void)fileName;
    (void)search;
    return 0;
}

int rl_FileTextReplace(const char *fileName, const char *search, const char *replacement)
{
    // TODO: implement wrapper for FileTextReplace
    (void)fileName;
    (void)search;
    (void)replacement;
    return 0;
}

Image rl_GenImageCellular(int width, int height, int tileSize)
{
    // TODO: implement wrapper for GenImageCellular
    (void)width;
    (void)height;
    (void)tileSize;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2)
{
    // TODO: implement wrapper for GenImageChecked
    (void)width;
    (void)height;
    (void)checksX;
    (void)checksY;
    (void)col1;
    (void)col2;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageColor(int width, int height, Color color)
{
    // TODO: implement wrapper for GenImageColor
    (void)width;
    (void)height;
    (void)color;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageFontAtlas(const GlyphInfo *glyphs, Rectangle **glyphRecs, int glyphCount, int fontSize, int padding, int packMethod)
{
    // TODO: implement wrapper for GenImageFontAtlas
    (void)glyphs;
    (void)glyphRecs;
    (void)glyphCount;
    (void)fontSize;
    (void)padding;
    (void)packMethod;
    // TODO: class C requires manual handling
    return (Image){0};
}

Image rl_GenImageGradientLinear(int width, int height, int direction, Color start, Color end)
{
    // TODO: implement wrapper for GenImageGradientLinear
    (void)width;
    (void)height;
    (void)direction;
    (void)start;
    (void)end;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageGradientRadial(int width, int height, float density, Color inner, Color outer)
{
    // TODO: implement wrapper for GenImageGradientRadial
    (void)width;
    (void)height;
    (void)density;
    (void)inner;
    (void)outer;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageGradientSquare(int width, int height, float density, Color inner, Color outer)
{
    // TODO: implement wrapper for GenImageGradientSquare
    (void)width;
    (void)height;
    (void)density;
    (void)inner;
    (void)outer;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale)
{
    // TODO: implement wrapper for GenImagePerlinNoise
    (void)width;
    (void)height;
    (void)offsetX;
    (void)offsetY;
    (void)scale;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageText(int width, int height, const char *text)
{
    // TODO: implement wrapper for GenImageText
    (void)width;
    (void)height;
    (void)text;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_GenImageWhiteNoise(int width, int height, float factor)
{
    // TODO: implement wrapper for GenImageWhiteNoise
    (void)width;
    (void)height;
    (void)factor;
    // TODO: class B requires manual handling
    return (Image){0};
}

Mesh rl_GenMeshCone(float radius, float height, int slices)
{
    // TODO: implement wrapper for GenMeshCone
    (void)radius;
    (void)height;
    (void)slices;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshCube(float width, float height, float length)
{
    // TODO: implement wrapper for GenMeshCube
    (void)width;
    (void)height;
    (void)length;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshCubicmap(Image cubicmap, Vector3 cubeSize)
{
    // TODO: implement wrapper for GenMeshCubicmap
    (void)cubicmap;
    (void)cubeSize;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshCylinder(float radius, float height, int slices)
{
    // TODO: implement wrapper for GenMeshCylinder
    (void)radius;
    (void)height;
    (void)slices;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshHeightmap(Image heightmap, Vector3 size)
{
    // TODO: implement wrapper for GenMeshHeightmap
    (void)heightmap;
    (void)size;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshHemiSphere(float radius, int rings, int slices)
{
    // TODO: implement wrapper for GenMeshHemiSphere
    (void)radius;
    (void)rings;
    (void)slices;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshKnot(float radius, float size, int radSeg, int sides)
{
    // TODO: implement wrapper for GenMeshKnot
    (void)radius;
    (void)size;
    (void)radSeg;
    (void)sides;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshPlane(float width, float length, int resX, int resZ)
{
    // TODO: implement wrapper for GenMeshPlane
    (void)width;
    (void)length;
    (void)resX;
    (void)resZ;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshPoly(int sides, float radius)
{
    // TODO: implement wrapper for GenMeshPoly
    (void)sides;
    (void)radius;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

Mesh rl_GenMeshSphere(float radius, int rings, int slices)
{
    // TODO: implement wrapper for GenMeshSphere
    (void)radius;
    (void)rings;
    (void)slices;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

void rl_GenMeshTangents(Mesh *mesh)
{
    // TODO: implement wrapper for GenMeshTangents
    (void)mesh;
    // TODO: class C requires manual handling
    return;
}

Mesh rl_GenMeshTorus(float radius, float size, int radSeg, int sides)
{
    // TODO: implement wrapper for GenMeshTorus
    (void)radius;
    (void)size;
    (void)radSeg;
    (void)sides;
    // TODO: class B requires manual handling
    return (Mesh){0};
}

void rl_GenTextureMipmaps(Texture2D *texture)
{
    // TODO: implement wrapper for GenTextureMipmaps
    (void)texture;
    // TODO: class C requires manual handling
    return;
}

const char * rl_GetApplicationDirectory(void)
{
    // TODO: implement wrapper for GetApplicationDirectory
    return NULL;
}

Matrix rl_GetCameraMatrix(Camera camera)
{
    // TODO: implement wrapper for GetCameraMatrix
    (void)camera;
    // TODO: class B requires manual handling
    return (Matrix){0};
}

Matrix rl_GetCameraMatrix2D(Camera2D camera)
{
    // TODO: implement wrapper for GetCameraMatrix2D
    (void)camera;
    // TODO: class B requires manual handling
    return (Matrix){0};
}

int rl_GetCharPressed(void)
{
    // TODO: implement wrapper for GetCharPressed
    return 0;
}

Image rl_GetClipboardImage(void)
{
    // TODO: implement wrapper for GetClipboardImage
    // TODO: class B requires manual handling
    return (Image){0};
}

const char * rl_GetClipboardText(void)
{
    // TODO: implement wrapper for GetClipboardText
    return NULL;
}

int rl_GetCodepoint(const char *text, int *codepointSize)
{
    // TODO: implement wrapper for GetCodepoint
    (void)text;
    (void)codepointSize;
    // TODO: class C requires manual handling
    return 0;
}

int rl_GetCodepointCount(const char *text)
{
    // TODO: implement wrapper for GetCodepointCount
    (void)text;
    return 0;
}

int rl_GetCodepointNext(const char *text, int *codepointSize)
{
    // TODO: implement wrapper for GetCodepointNext
    (void)text;
    (void)codepointSize;
    // TODO: class C requires manual handling
    return 0;
}

int rl_GetCodepointPrevious(const char *text, int *codepointSize)
{
    // TODO: implement wrapper for GetCodepointPrevious
    (void)text;
    (void)codepointSize;
    // TODO: class C requires manual handling
    return 0;
}

Rectangle rl_GetCollisionRec(Rectangle rec1, Rectangle rec2)
{
    // TODO: implement wrapper for GetCollisionRec
    (void)rec1;
    (void)rec2;
    // TODO: class B requires manual handling
    return (Rectangle){0};
}

Color rl_GetColor(unsigned int hexValue)
{
    // TODO: implement wrapper for GetColor
    (void)hexValue;
    // TODO: class B requires manual handling
    return (Color){0};
}

int rl_GetCurrentMonitor(void)
{
    // TODO: implement wrapper for GetCurrentMonitor
    return 0;
}

unsigned int rl_GetDirectoryFileCount(const char *dirPath)
{
    // TODO: implement wrapper for GetDirectoryFileCount
    (void)dirPath;
    return 0;
}

unsigned int rl_GetDirectoryFileCountEx(const char *basePath, const char *filter, bool scanSubdirs)
{
    // TODO: implement wrapper for GetDirectoryFileCountEx
    (void)basePath;
    (void)filter;
    (void)scanSubdirs;
    // TODO: class B requires manual handling
    return 0;
}

const char * rl_GetDirectoryPath(const char *filePath)
{
    // TODO: implement wrapper for GetDirectoryPath
    (void)filePath;
    return NULL;
}

int rl_GetFPS(void)
{
    // TODO: implement wrapper for GetFPS
    return 0;
}

const char * rl_GetFileExtension(const char *fileName)
{
    // TODO: implement wrapper for GetFileExtension
    (void)fileName;
    return NULL;
}

int rl_GetFileLength(const char *fileName)
{
    // TODO: implement wrapper for GetFileLength
    (void)fileName;
    return 0;
}

long rl_GetFileModTime(const char *fileName)
{
    // TODO: implement wrapper for GetFileModTime
    (void)fileName;
    return 0;
}

const char * rl_GetFileName(const char *filePath)
{
    // TODO: implement wrapper for GetFileName
    (void)filePath;
    return NULL;
}

const char * rl_GetFileNameWithoutExt(const char *filePath)
{
    // TODO: implement wrapper for GetFileNameWithoutExt
    (void)filePath;
    return NULL;
}

Font rl_GetFontDefault(void)
{
    // TODO: implement wrapper for GetFontDefault
    // TODO: class B requires manual handling
    return (Font){0};
}

float rl_GetFrameTime(void)
{
    // TODO: implement wrapper for GetFrameTime
    return 0;
}

int rl_GetGamepadAxisCount(int gamepad)
{
    // TODO: implement wrapper for GetGamepadAxisCount
    (void)gamepad;
    return 0;
}

float rl_GetGamepadAxisMovement(int gamepad, int axis)
{
    // TODO: implement wrapper for GetGamepadAxisMovement
    (void)gamepad;
    (void)axis;
    return 0;
}

int rl_GetGamepadButtonPressed(void)
{
    // TODO: implement wrapper for GetGamepadButtonPressed
    return 0;
}

const char * rl_GetGamepadName(int gamepad)
{
    // TODO: implement wrapper for GetGamepadName
    (void)gamepad;
    return NULL;
}

int rl_GetGestureDetected(void)
{
    // TODO: implement wrapper for GetGestureDetected
    return 0;
}

float rl_GetGestureDragAngle(void)
{
    // TODO: implement wrapper for GetGestureDragAngle
    return 0;
}

Vector2 rl_GetGestureDragVector(void)
{
    // TODO: implement wrapper for GetGestureDragVector
    // TODO: class B requires manual handling
    return (Vector2){0};
}

float rl_GetGestureHoldDuration(void)
{
    // TODO: implement wrapper for GetGestureHoldDuration
    return 0;
}

float rl_GetGesturePinchAngle(void)
{
    // TODO: implement wrapper for GetGesturePinchAngle
    return 0;
}

Vector2 rl_GetGesturePinchVector(void)
{
    // TODO: implement wrapper for GetGesturePinchVector
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Rectangle rl_GetGlyphAtlasRec(Font font, int codepoint)
{
    // TODO: implement wrapper for GetGlyphAtlasRec
    (void)font;
    (void)codepoint;
    // TODO: class B requires manual handling
    return (Rectangle){0};
}

int rl_GetGlyphIndex(Font font, int codepoint)
{
    // TODO: implement wrapper for GetGlyphIndex
    (void)font;
    (void)codepoint;
    // TODO: class B requires manual handling
    return 0;
}

GlyphInfo rl_GetGlyphInfo(Font font, int codepoint)
{
    // TODO: implement wrapper for GetGlyphInfo
    (void)font;
    (void)codepoint;
    // TODO: class B requires manual handling
    return (GlyphInfo){0};
}

Rectangle rl_GetImageAlphaBorder(Image image, float threshold)
{
    // TODO: implement wrapper for GetImageAlphaBorder
    (void)image;
    (void)threshold;
    // TODO: class B requires manual handling
    return (Rectangle){0};
}

Color rl_GetImageColor(Image image, int x, int y)
{
    // TODO: implement wrapper for GetImageColor
    (void)image;
    (void)x;
    (void)y;
    // TODO: class B requires manual handling
    return (Color){0};
}

const char * rl_GetKeyName(int key)
{
    // TODO: implement wrapper for GetKeyName
    (void)key;
    return NULL;
}

int rl_GetKeyPressed(void)
{
    // TODO: implement wrapper for GetKeyPressed
    return 0;
}

float rl_GetMasterVolume(void)
{
    // TODO: implement wrapper for GetMasterVolume
    return 0;
}

BoundingBox rl_GetMeshBoundingBox(Mesh mesh)
{
    // TODO: implement wrapper for GetMeshBoundingBox
    (void)mesh;
    // TODO: class B requires manual handling
    return (BoundingBox){0};
}

BoundingBox rl_GetModelBoundingBox(Model model)
{
    // TODO: implement wrapper for GetModelBoundingBox
    (void)model;
    // TODO: class B requires manual handling
    return (BoundingBox){0};
}

int rl_GetMonitorCount(void)
{
    // TODO: implement wrapper for GetMonitorCount
    return 0;
}

int rl_GetMonitorHeight(int monitor)
{
    // TODO: implement wrapper for GetMonitorHeight
    (void)monitor;
    return 0;
}

const char * rl_GetMonitorName(int monitor)
{
    // TODO: implement wrapper for GetMonitorName
    (void)monitor;
    return NULL;
}

int rl_GetMonitorPhysicalHeight(int monitor)
{
    // TODO: implement wrapper for GetMonitorPhysicalHeight
    (void)monitor;
    return 0;
}

int rl_GetMonitorPhysicalWidth(int monitor)
{
    // TODO: implement wrapper for GetMonitorPhysicalWidth
    (void)monitor;
    return 0;
}

Vector2 rl_GetMonitorPosition(int monitor)
{
    // TODO: implement wrapper for GetMonitorPosition
    (void)monitor;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

int rl_GetMonitorRefreshRate(int monitor)
{
    // TODO: implement wrapper for GetMonitorRefreshRate
    (void)monitor;
    return 0;
}

int rl_GetMonitorWidth(int monitor)
{
    // TODO: implement wrapper for GetMonitorWidth
    (void)monitor;
    return 0;
}

Vector2 rl_GetMouseDelta(void)
{
    // TODO: implement wrapper for GetMouseDelta
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetMousePosition(void)
{
    // TODO: implement wrapper for GetMousePosition
    // TODO: class B requires manual handling
    return (Vector2){0};
}

float rl_GetMouseWheelMove(void)
{
    // TODO: implement wrapper for GetMouseWheelMove
    return 0;
}

Vector2 rl_GetMouseWheelMoveV(void)
{
    // TODO: implement wrapper for GetMouseWheelMoveV
    // TODO: class B requires manual handling
    return (Vector2){0};
}

int rl_GetMouseX(void)
{
    // TODO: implement wrapper for GetMouseX
    return 0;
}

int rl_GetMouseY(void)
{
    // TODO: implement wrapper for GetMouseY
    return 0;
}

float rl_GetMusicTimeLength(Music music)
{
    // TODO: implement wrapper for GetMusicTimeLength
    (void)music;
    // TODO: class B requires manual handling
    return 0;
}

float rl_GetMusicTimePlayed(Music music)
{
    // TODO: implement wrapper for GetMusicTimePlayed
    (void)music;
    // TODO: class B requires manual handling
    return 0;
}

Color rl_GetPixelColor(void *srcPtr, int format)
{
    // TODO: implement wrapper for GetPixelColor
    (void)srcPtr;
    (void)format;
    // TODO: class C requires manual handling
    return (Color){0};
}

int rl_GetPixelDataSize(int width, int height, int format)
{
    // TODO: implement wrapper for GetPixelDataSize
    (void)width;
    (void)height;
    (void)format;
    return 0;
}

const char * rl_GetPrevDirectoryPath(const char *dirPath)
{
    // TODO: implement wrapper for GetPrevDirectoryPath
    (void)dirPath;
    return NULL;
}

int rl_GetRandomValue(int min, int max)
{
    // TODO: implement wrapper for GetRandomValue
    (void)min;
    (void)max;
    return 0;
}

RayCollision rl_GetRayCollisionBox(Ray ray, BoundingBox box)
{
    // TODO: implement wrapper for GetRayCollisionBox
    (void)ray;
    (void)box;
    // TODO: class B requires manual handling
    return (RayCollision){0};
}

RayCollision rl_GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform)
{
    // TODO: implement wrapper for GetRayCollisionMesh
    (void)ray;
    (void)mesh;
    (void)transform;
    // TODO: class B requires manual handling
    return (RayCollision){0};
}

RayCollision rl_GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4)
{
    // TODO: implement wrapper for GetRayCollisionQuad
    (void)ray;
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    // TODO: class B requires manual handling
    return (RayCollision){0};
}

RayCollision rl_GetRayCollisionSphere(Ray ray, Vector3 center, float radius)
{
    // TODO: implement wrapper for GetRayCollisionSphere
    (void)ray;
    (void)center;
    (void)radius;
    // TODO: class B requires manual handling
    return (RayCollision){0};
}

RayCollision rl_GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3)
{
    // TODO: implement wrapper for GetRayCollisionTriangle
    (void)ray;
    (void)p1;
    (void)p2;
    (void)p3;
    // TODO: class B requires manual handling
    return (RayCollision){0};
}

int rl_GetRenderHeight(void)
{
    // TODO: implement wrapper for GetRenderHeight
    return 0;
}

int rl_GetRenderWidth(void)
{
    // TODO: implement wrapper for GetRenderWidth
    return 0;
}

int rl_GetScreenHeight(void)
{
    // TODO: implement wrapper for GetScreenHeight
    return 0;
}

Vector2 rl_GetScreenToWorld2D(Vector2 position, Camera2D camera)
{
    // TODO: implement wrapper for GetScreenToWorld2D
    (void)position;
    (void)camera;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Ray rl_GetScreenToWorldRay(Vector2 position, Camera camera)
{
    // TODO: implement wrapper for GetScreenToWorldRay
    (void)position;
    (void)camera;
    // TODO: class B requires manual handling
    return (Ray){0};
}

Ray rl_GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height)
{
    // TODO: implement wrapper for GetScreenToWorldRayEx
    (void)position;
    (void)camera;
    (void)width;
    (void)height;
    // TODO: class B requires manual handling
    return (Ray){0};
}

int rl_GetScreenWidth(void)
{
    // TODO: implement wrapper for GetScreenWidth
    return 0;
}

int rl_GetShaderLocation(Shader shader, const char *uniformName)
{
    // TODO: implement wrapper for GetShaderLocation
    (void)shader;
    (void)uniformName;
    // TODO: class B requires manual handling
    return 0;
}

int rl_GetShaderLocationAttrib(Shader shader, const char *attribName)
{
    // TODO: implement wrapper for GetShaderLocationAttrib
    (void)shader;
    (void)attribName;
    // TODO: class B requires manual handling
    return 0;
}

Texture2D rl_GetShapesTexture(void)
{
    // TODO: implement wrapper for GetShapesTexture
    // TODO: class B requires manual handling
    return (Texture2D){0};
}

Rectangle rl_GetShapesTextureRectangle(void)
{
    // TODO: implement wrapper for GetShapesTextureRectangle
    // TODO: class B requires manual handling
    return (Rectangle){0};
}

Vector2 rl_GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)
{
    // TODO: implement wrapper for GetSplinePointBasis
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    (void)t;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t)
{
    // TODO: implement wrapper for GetSplinePointBezierCubic
    (void)p1;
    (void)c2;
    (void)c3;
    (void)p4;
    (void)t;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t)
{
    // TODO: implement wrapper for GetSplinePointBezierQuad
    (void)p1;
    (void)c2;
    (void)p3;
    (void)t;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)
{
    // TODO: implement wrapper for GetSplinePointCatmullRom
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    (void)t;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t)
{
    // TODO: implement wrapper for GetSplinePointLinear
    (void)startPos;
    (void)endPos;
    (void)t;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

char * rl_GetTextBetween(const char *text, const char *begin, const char *end)
{
    // TODO: implement wrapper for GetTextBetween
    (void)text;
    (void)begin;
    (void)end;
    return NULL;
}

double rl_GetTime(void)
{
    // TODO: implement wrapper for GetTime
    return 0;
}

int rl_GetTouchPointCount(void)
{
    // TODO: implement wrapper for GetTouchPointCount
    return 0;
}

int rl_GetTouchPointId(int index)
{
    // TODO: implement wrapper for GetTouchPointId
    (void)index;
    return 0;
}

Vector2 rl_GetTouchPosition(int index)
{
    // TODO: implement wrapper for GetTouchPosition
    (void)index;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

int rl_GetTouchX(void)
{
    // TODO: implement wrapper for GetTouchX
    return 0;
}

int rl_GetTouchY(void)
{
    // TODO: implement wrapper for GetTouchY
    return 0;
}

void * rl_GetWindowHandle(void)
{
    // TODO: implement wrapper for GetWindowHandle
    // TODO: class B requires manual handling
    return NULL;
}

Vector2 rl_GetWindowPosition(void)
{
    // TODO: implement wrapper for GetWindowPosition
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetWindowScaleDPI(void)
{
    // TODO: implement wrapper for GetWindowScaleDPI
    // TODO: class B requires manual handling
    return (Vector2){0};
}

const char * rl_GetWorkingDirectory(void)
{
    // TODO: implement wrapper for GetWorkingDirectory
    return NULL;
}

Vector2 rl_GetWorldToScreen(Vector3 position, Camera camera)
{
    // TODO: implement wrapper for GetWorldToScreen
    (void)position;
    (void)camera;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetWorldToScreen2D(Vector2 position, Camera2D camera)
{
    // TODO: implement wrapper for GetWorldToScreen2D
    (void)position;
    (void)camera;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

Vector2 rl_GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height)
{
    // TODO: implement wrapper for GetWorldToScreenEx
    (void)position;
    (void)camera;
    (void)width;
    (void)height;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

void rl_HideCursor(void)
{
    // TODO: implement wrapper for HideCursor
    return;
}

void rl_ImageAlphaClear(Image *image, Color color, float threshold)
{
    // TODO: implement wrapper for ImageAlphaClear
    (void)image;
    (void)color;
    (void)threshold;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageAlphaCrop(Image *image, float threshold)
{
    // TODO: implement wrapper for ImageAlphaCrop
    (void)image;
    (void)threshold;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageAlphaMask(Image *image, Image alphaMask)
{
    // TODO: implement wrapper for ImageAlphaMask
    (void)image;
    (void)alphaMask;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageAlphaPremultiply(Image *image)
{
    // TODO: implement wrapper for ImageAlphaPremultiply
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageBlurGaussian(Image *image, int blurSize)
{
    // TODO: implement wrapper for ImageBlurGaussian
    (void)image;
    (void)blurSize;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageClearBackground(Image *dst, Color color)
{
    // TODO: implement wrapper for ImageClearBackground
    (void)dst;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorBrightness(Image *image, int brightness)
{
    // TODO: implement wrapper for ImageColorBrightness
    (void)image;
    (void)brightness;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorContrast(Image *image, float contrast)
{
    // TODO: implement wrapper for ImageColorContrast
    (void)image;
    (void)contrast;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorGrayscale(Image *image)
{
    // TODO: implement wrapper for ImageColorGrayscale
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorInvert(Image *image)
{
    // TODO: implement wrapper for ImageColorInvert
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorReplace(Image *image, Color color, Color replace)
{
    // TODO: implement wrapper for ImageColorReplace
    (void)image;
    (void)color;
    (void)replace;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageColorTint(Image *image, Color color)
{
    // TODO: implement wrapper for ImageColorTint
    (void)image;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

Image rl_ImageCopy(Image image)
{
    // TODO: implement wrapper for ImageCopy
    (void)image;
    // TODO: class B requires manual handling
    return (Image){0};
}

void rl_ImageCrop(Image *image, Rectangle crop)
{
    // TODO: implement wrapper for ImageCrop
    (void)image;
    (void)crop;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp)
{
    // TODO: implement wrapper for ImageDither
    (void)image;
    (void)rBpp;
    (void)gBpp;
    (void)bBpp;
    (void)aBpp;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint)
{
    // TODO: implement wrapper for ImageDraw
    (void)dst;
    (void)src;
    (void)srcRec;
    (void)dstRec;
    (void)tint;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color)
{
    // TODO: implement wrapper for ImageDrawCircle
    (void)dst;
    (void)centerX;
    (void)centerY;
    (void)radius;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawCircleLines(Image *dst, int centerX, int centerY, int radius, Color color)
{
    // TODO: implement wrapper for ImageDrawCircleLines
    (void)dst;
    (void)centerX;
    (void)centerY;
    (void)radius;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawCircleLinesV(Image *dst, Vector2 center, int radius, Color color)
{
    // TODO: implement wrapper for ImageDrawCircleLinesV
    (void)dst;
    (void)center;
    (void)radius;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color)
{
    // TODO: implement wrapper for ImageDrawCircleV
    (void)dst;
    (void)center;
    (void)radius;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    // TODO: implement wrapper for ImageDrawLine
    (void)dst;
    (void)startPosX;
    (void)startPosY;
    (void)endPosX;
    (void)endPosY;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawLineEx(Image *dst, Vector2 start, Vector2 end, int thick, Color color)
{
    // TODO: implement wrapper for ImageDrawLineEx
    (void)dst;
    (void)start;
    (void)end;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color)
{
    // TODO: implement wrapper for ImageDrawLineV
    (void)dst;
    (void)start;
    (void)end;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawPixel(Image *dst, int posX, int posY, Color color)
{
    // TODO: implement wrapper for ImageDrawPixel
    (void)dst;
    (void)posX;
    (void)posY;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawPixelV(Image *dst, Vector2 position, Color color)
{
    // TODO: implement wrapper for ImageDrawPixelV
    (void)dst;
    (void)position;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color)
{
    // TODO: implement wrapper for ImageDrawRectangle
    (void)dst;
    (void)posX;
    (void)posY;
    (void)width;
    (void)height;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color)
{
    // TODO: implement wrapper for ImageDrawRectangleLines
    (void)dst;
    (void)rec;
    (void)thick;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color)
{
    // TODO: implement wrapper for ImageDrawRectangleRec
    (void)dst;
    (void)rec;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color)
{
    // TODO: implement wrapper for ImageDrawRectangleV
    (void)dst;
    (void)position;
    (void)size;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color)
{
    // TODO: implement wrapper for ImageDrawText
    (void)dst;
    (void)text;
    (void)posX;
    (void)posY;
    (void)fontSize;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    // TODO: implement wrapper for ImageDrawTextEx
    (void)dst;
    (void)font;
    (void)text;
    (void)position;
    (void)fontSize;
    (void)spacing;
    (void)tint;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTriangle(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    // TODO: implement wrapper for ImageDrawTriangle
    (void)dst;
    (void)v1;
    (void)v2;
    (void)v3;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTriangleEx(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3)
{
    // TODO: implement wrapper for ImageDrawTriangleEx
    (void)dst;
    (void)v1;
    (void)v2;
    (void)v3;
    (void)c1;
    (void)c2;
    (void)c3;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTriangleFan(Image *dst, const Vector2 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for ImageDrawTriangleFan
    (void)dst;
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTriangleLines(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    // TODO: implement wrapper for ImageDrawTriangleLines
    (void)dst;
    (void)v1;
    (void)v2;
    (void)v3;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageDrawTriangleStrip(Image *dst, const Vector2 *points, int pointCount, Color color)
{
    // TODO: implement wrapper for ImageDrawTriangleStrip
    (void)dst;
    (void)points;
    (void)pointCount;
    (void)color;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageFlipHorizontal(Image *image)
{
    // TODO: implement wrapper for ImageFlipHorizontal
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageFlipVertical(Image *image)
{
    // TODO: implement wrapper for ImageFlipVertical
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageFormat(Image *image, int newFormat)
{
    // TODO: implement wrapper for ImageFormat
    (void)image;
    (void)newFormat;
    // TODO: class C requires manual handling
    return;
}

Image rl_ImageFromChannel(Image image, int selectedChannel)
{
    // TODO: implement wrapper for ImageFromChannel
    (void)image;
    (void)selectedChannel;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_ImageFromImage(Image image, Rectangle rec)
{
    // TODO: implement wrapper for ImageFromImage
    (void)image;
    (void)rec;
    // TODO: class B requires manual handling
    return (Image){0};
}

void rl_ImageKernelConvolution(Image *image, const float *kernel, int kernelSize)
{
    // TODO: implement wrapper for ImageKernelConvolution
    (void)image;
    (void)kernel;
    (void)kernelSize;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageMipmaps(Image *image)
{
    // TODO: implement wrapper for ImageMipmaps
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageResize(Image *image, int newWidth, int newHeight)
{
    // TODO: implement wrapper for ImageResize
    (void)image;
    (void)newWidth;
    (void)newHeight;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill)
{
    // TODO: implement wrapper for ImageResizeCanvas
    (void)image;
    (void)newWidth;
    (void)newHeight;
    (void)offsetX;
    (void)offsetY;
    (void)fill;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageResizeNN(Image *image, int newWidth, int newHeight)
{
    // TODO: implement wrapper for ImageResizeNN
    (void)image;
    (void)newWidth;
    (void)newHeight;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageRotate(Image *image, int degrees)
{
    // TODO: implement wrapper for ImageRotate
    (void)image;
    (void)degrees;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageRotateCCW(Image *image)
{
    // TODO: implement wrapper for ImageRotateCCW
    (void)image;
    // TODO: class C requires manual handling
    return;
}

void rl_ImageRotateCW(Image *image)
{
    // TODO: implement wrapper for ImageRotateCW
    (void)image;
    // TODO: class C requires manual handling
    return;
}

Image rl_ImageText(const char *text, int fontSize, Color color)
{
    // TODO: implement wrapper for ImageText
    (void)text;
    (void)fontSize;
    (void)color;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint)
{
    // TODO: implement wrapper for ImageTextEx
    (void)font;
    (void)text;
    (void)fontSize;
    (void)spacing;
    (void)tint;
    // TODO: class B requires manual handling
    return (Image){0};
}

void rl_ImageToPOT(Image *image, Color fill)
{
    // TODO: implement wrapper for ImageToPOT
    (void)image;
    (void)fill;
    // TODO: class C requires manual handling
    return;
}

void rl_InitAudioDevice(void)
{
    // TODO: implement wrapper for InitAudioDevice
    return;
}

void rl_InitWindow(int width, int height, const char *title)
{
    // TODO: implement wrapper for InitWindow
    (void)width;
    (void)height;
    (void)title;
    return;
}

bool rl_IsAudioDeviceReady(void)
{
    // TODO: implement wrapper for IsAudioDeviceReady
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsAudioStreamPlaying(AudioStream stream)
{
    // TODO: implement wrapper for IsAudioStreamPlaying
    (void)stream;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsAudioStreamProcessed(AudioStream stream)
{
    // TODO: implement wrapper for IsAudioStreamProcessed
    (void)stream;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsAudioStreamValid(AudioStream stream)
{
    // TODO: implement wrapper for IsAudioStreamValid
    (void)stream;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsCursorHidden(void)
{
    // TODO: implement wrapper for IsCursorHidden
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsCursorOnScreen(void)
{
    // TODO: implement wrapper for IsCursorOnScreen
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsFileDropped(void)
{
    // TODO: implement wrapper for IsFileDropped
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsFileExtension(const char *fileName, const char *ext)
{
    // TODO: implement wrapper for IsFileExtension
    (void)fileName;
    (void)ext;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsFileNameValid(const char *fileName)
{
    // TODO: implement wrapper for IsFileNameValid
    (void)fileName;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsFontValid(Font font)
{
    // TODO: implement wrapper for IsFontValid
    (void)font;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGamepadAvailable(int gamepad)
{
    // TODO: implement wrapper for IsGamepadAvailable
    (void)gamepad;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGamepadButtonDown(int gamepad, int button)
{
    // TODO: implement wrapper for IsGamepadButtonDown
    (void)gamepad;
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGamepadButtonPressed(int gamepad, int button)
{
    // TODO: implement wrapper for IsGamepadButtonPressed
    (void)gamepad;
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGamepadButtonReleased(int gamepad, int button)
{
    // TODO: implement wrapper for IsGamepadButtonReleased
    (void)gamepad;
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGamepadButtonUp(int gamepad, int button)
{
    // TODO: implement wrapper for IsGamepadButtonUp
    (void)gamepad;
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsGestureDetected(unsigned int gesture)
{
    // TODO: implement wrapper for IsGestureDetected
    (void)gesture;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsImageValid(Image image)
{
    // TODO: implement wrapper for IsImageValid
    (void)image;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsKeyDown(int key)
{
    // TODO: implement wrapper for IsKeyDown
    (void)key;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsKeyPressed(int key)
{
    // TODO: implement wrapper for IsKeyPressed
    (void)key;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsKeyPressedRepeat(int key)
{
    // TODO: implement wrapper for IsKeyPressedRepeat
    (void)key;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsKeyReleased(int key)
{
    // TODO: implement wrapper for IsKeyReleased
    (void)key;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsKeyUp(int key)
{
    // TODO: implement wrapper for IsKeyUp
    (void)key;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMaterialValid(Material material)
{
    // TODO: implement wrapper for IsMaterialValid
    (void)material;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsModelAnimationValid(Model model, ModelAnimation anim)
{
    // TODO: implement wrapper for IsModelAnimationValid
    (void)model;
    (void)anim;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsModelValid(Model model)
{
    // TODO: implement wrapper for IsModelValid
    (void)model;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMouseButtonDown(int button)
{
    // TODO: implement wrapper for IsMouseButtonDown
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMouseButtonPressed(int button)
{
    // TODO: implement wrapper for IsMouseButtonPressed
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMouseButtonReleased(int button)
{
    // TODO: implement wrapper for IsMouseButtonReleased
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMouseButtonUp(int button)
{
    // TODO: implement wrapper for IsMouseButtonUp
    (void)button;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMusicStreamPlaying(Music music)
{
    // TODO: implement wrapper for IsMusicStreamPlaying
    (void)music;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsMusicValid(Music music)
{
    // TODO: implement wrapper for IsMusicValid
    (void)music;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsPathFile(const char *path)
{
    // TODO: implement wrapper for IsPathFile
    (void)path;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsRenderTextureValid(RenderTexture2D target)
{
    // TODO: implement wrapper for IsRenderTextureValid
    (void)target;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsShaderValid(Shader shader)
{
    // TODO: implement wrapper for IsShaderValid
    (void)shader;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsSoundPlaying(Sound sound)
{
    // TODO: implement wrapper for IsSoundPlaying
    (void)sound;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsSoundValid(Sound sound)
{
    // TODO: implement wrapper for IsSoundValid
    (void)sound;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsTextureValid(Texture2D texture)
{
    // TODO: implement wrapper for IsTextureValid
    (void)texture;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWaveValid(Wave wave)
{
    // TODO: implement wrapper for IsWaveValid
    (void)wave;
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowFocused(void)
{
    // TODO: implement wrapper for IsWindowFocused
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowFullscreen(void)
{
    // TODO: implement wrapper for IsWindowFullscreen
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowHidden(void)
{
    // TODO: implement wrapper for IsWindowHidden
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowMaximized(void)
{
    // TODO: implement wrapper for IsWindowMaximized
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowMinimized(void)
{
    // TODO: implement wrapper for IsWindowMinimized
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowReady(void)
{
    // TODO: implement wrapper for IsWindowReady
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowResized(void)
{
    // TODO: implement wrapper for IsWindowResized
    // TODO: class B requires manual handling
    return false;
}

bool rl_IsWindowState(unsigned int flag)
{
    // TODO: implement wrapper for IsWindowState
    (void)flag;
    // TODO: class B requires manual handling
    return false;
}

AudioStream rl_LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)
{
    // TODO: implement wrapper for LoadAudioStream
    (void)sampleRate;
    (void)sampleSize;
    (void)channels;
    // TODO: class B requires manual handling
    return (AudioStream){0};
}

AutomationEventList rl_LoadAutomationEventList(const char *fileName)
{
    // TODO: implement wrapper for LoadAutomationEventList
    (void)fileName;
    // TODO: class B requires manual handling
    return (AutomationEventList){0};
}

int * rl_LoadCodepoints(const char *text, int *count)
{
    // TODO: implement wrapper for LoadCodepoints
    (void)text;
    (void)count;
    // TODO: class C requires manual handling
    return NULL;
}

FilePathList rl_LoadDirectoryFiles(const char *dirPath)
{
    // TODO: implement wrapper for LoadDirectoryFiles
    (void)dirPath;
    // TODO: class B requires manual handling
    return (FilePathList){0};
}

FilePathList rl_LoadDirectoryFilesEx(const char *basePath, const char *filter, bool scanSubdirs)
{
    // TODO: implement wrapper for LoadDirectoryFilesEx
    (void)basePath;
    (void)filter;
    (void)scanSubdirs;
    // TODO: class B requires manual handling
    return (FilePathList){0};
}

FilePathList rl_LoadDroppedFiles(void)
{
    // TODO: implement wrapper for LoadDroppedFiles
    // TODO: class B requires manual handling
    return (FilePathList){0};
}

unsigned char * rl_LoadFileData(const char *fileName, int *dataSize)
{
    // TODO: implement wrapper for LoadFileData
    (void)fileName;
    (void)dataSize;
    // TODO: class C requires manual handling
    return NULL;
}

char * rl_LoadFileText(const char *fileName)
{
    // TODO: implement wrapper for LoadFileText
    (void)fileName;
    return NULL;
}

Font rl_LoadFont(const char *fileName)
{
    // TODO: implement wrapper for LoadFont
    (void)fileName;
    // TODO: class B requires manual handling
    return (Font){0};
}

GlyphInfo * rl_LoadFontData(const unsigned char *fileData, int dataSize, int fontSize, const int *codepoints, int codepointCount, int type, int *glyphCount)
{
    // TODO: implement wrapper for LoadFontData
    (void)fileData;
    (void)dataSize;
    (void)fontSize;
    (void)codepoints;
    (void)codepointCount;
    (void)type;
    (void)glyphCount;
    // TODO: class C requires manual handling
    return NULL;
}

Font rl_LoadFontEx(const char *fileName, int fontSize, const int *codepoints, int codepointCount)
{
    // TODO: implement wrapper for LoadFontEx
    (void)fileName;
    (void)fontSize;
    (void)codepoints;
    (void)codepointCount;
    // TODO: class C requires manual handling
    return (Font){0};
}

Font rl_LoadFontFromImage(Image image, Color key, int firstChar)
{
    // TODO: implement wrapper for LoadFontFromImage
    (void)image;
    (void)key;
    (void)firstChar;
    // TODO: class B requires manual handling
    return (Font){0};
}

Font rl_LoadFontFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, const int *codepoints, int codepointCount)
{
    // TODO: implement wrapper for LoadFontFromMemory
    (void)fileType;
    (void)fileData;
    (void)dataSize;
    (void)fontSize;
    (void)codepoints;
    (void)codepointCount;
    // TODO: class C requires manual handling
    return (Font){0};
}

Image rl_LoadImage(const char *fileName)
{
    // TODO: implement wrapper for LoadImage
    (void)fileName;
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_LoadImageAnim(const char *fileName, int *frames)
{
    // TODO: implement wrapper for LoadImageAnim
    (void)fileName;
    (void)frames;
    // TODO: class C requires manual handling
    return (Image){0};
}

Image rl_LoadImageAnimFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int *frames)
{
    // TODO: implement wrapper for LoadImageAnimFromMemory
    (void)fileType;
    (void)fileData;
    (void)dataSize;
    (void)frames;
    // TODO: class C requires manual handling
    return (Image){0};
}

Color * rl_LoadImageColors(Image image)
{
    // TODO: implement wrapper for LoadImageColors
    (void)image;
    // TODO: class B requires manual handling
    return NULL;
}

Image rl_LoadImageFromMemory(const char *fileType, const unsigned char *fileData, int dataSize)
{
    // TODO: implement wrapper for LoadImageFromMemory
    (void)fileType;
    (void)fileData;
    (void)dataSize;
    // TODO: class C requires manual handling
    return (Image){0};
}

Image rl_LoadImageFromScreen(void)
{
    // TODO: implement wrapper for LoadImageFromScreen
    // TODO: class B requires manual handling
    return (Image){0};
}

Image rl_LoadImageFromTexture(Texture2D texture)
{
    // TODO: implement wrapper for LoadImageFromTexture
    (void)texture;
    // TODO: class B requires manual handling
    return (Image){0};
}

Color * rl_LoadImagePalette(Image image, int maxPaletteSize, int *colorCount)
{
    // TODO: implement wrapper for LoadImagePalette
    (void)image;
    (void)maxPaletteSize;
    (void)colorCount;
    // TODO: class C requires manual handling
    return NULL;
}

Image rl_LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize)
{
    // TODO: implement wrapper for LoadImageRaw
    (void)fileName;
    (void)width;
    (void)height;
    (void)format;
    (void)headerSize;
    // TODO: class B requires manual handling
    return (Image){0};
}

Material rl_LoadMaterialDefault(void)
{
    // TODO: implement wrapper for LoadMaterialDefault
    // TODO: class B requires manual handling
    return (Material){0};
}

Material * rl_LoadMaterials(const char *fileName, int *materialCount)
{
    // TODO: implement wrapper for LoadMaterials
    (void)fileName;
    (void)materialCount;
    // TODO: class C requires manual handling
    return NULL;
}

Model rl_LoadModel(const char *fileName)
{
    // TODO: implement wrapper for LoadModel
    (void)fileName;
    // TODO: class B requires manual handling
    return (Model){0};
}

ModelAnimation * rl_LoadModelAnimations(const char *fileName, int *animCount)
{
    // TODO: implement wrapper for LoadModelAnimations
    (void)fileName;
    (void)animCount;
    // TODO: class C requires manual handling
    return NULL;
}

Model rl_LoadModelFromMesh(Mesh mesh)
{
    // TODO: implement wrapper for LoadModelFromMesh
    (void)mesh;
    // TODO: class B requires manual handling
    return (Model){0};
}

Music rl_LoadMusicStream(const char *fileName)
{
    // TODO: implement wrapper for LoadMusicStream
    (void)fileName;
    // TODO: class B requires manual handling
    return (Music){0};
}

Music rl_LoadMusicStreamFromMemory(const char *fileType, const unsigned char *data, int dataSize)
{
    // TODO: implement wrapper for LoadMusicStreamFromMemory
    (void)fileType;
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return (Music){0};
}

int * rl_LoadRandomSequence(unsigned int count, int min, int max)
{
    // TODO: implement wrapper for LoadRandomSequence
    (void)count;
    (void)min;
    (void)max;
    // TODO: class B requires manual handling
    return NULL;
}

RenderTexture2D rl_LoadRenderTexture(int width, int height)
{
    // TODO: implement wrapper for LoadRenderTexture
    (void)width;
    (void)height;
    // TODO: class B requires manual handling
    return (RenderTexture2D){0};
}

Shader rl_LoadShader(const char *vsFileName, const char *fsFileName)
{
    // TODO: implement wrapper for LoadShader
    (void)vsFileName;
    (void)fsFileName;
    // TODO: class B requires manual handling
    return (Shader){0};
}

Shader rl_LoadShaderFromMemory(const char *vsCode, const char *fsCode)
{
    // TODO: implement wrapper for LoadShaderFromMemory
    (void)vsCode;
    (void)fsCode;
    // TODO: class B requires manual handling
    return (Shader){0};
}

Sound rl_LoadSound(const char *fileName)
{
    // TODO: implement wrapper for LoadSound
    (void)fileName;
    // TODO: class B requires manual handling
    return (Sound){0};
}

Sound rl_LoadSoundAlias(Sound source)
{
    // TODO: implement wrapper for LoadSoundAlias
    (void)source;
    // TODO: class B requires manual handling
    return (Sound){0};
}

Sound rl_LoadSoundFromWave(Wave wave)
{
    // TODO: implement wrapper for LoadSoundFromWave
    (void)wave;
    // TODO: class B requires manual handling
    return (Sound){0};
}

char ** rl_LoadTextLines(const char *text, int *count)
{
    // TODO: implement wrapper for LoadTextLines
    (void)text;
    (void)count;
    // TODO: class C requires manual handling
    return NULL;
}

Texture2D rl_LoadTexture(const char *fileName)
{
    // TODO: implement wrapper for LoadTexture
    (void)fileName;
    // TODO: class B requires manual handling
    return (Texture2D){0};
}

TextureCubemap rl_LoadTextureCubemap(Image image, int layout)
{
    // TODO: implement wrapper for LoadTextureCubemap
    (void)image;
    (void)layout;
    // TODO: class B requires manual handling
    return (TextureCubemap){0};
}

Texture2D rl_LoadTextureFromImage(Image image)
{
    // TODO: implement wrapper for LoadTextureFromImage
    (void)image;
    // TODO: class B requires manual handling
    return (Texture2D){0};
}

char * rl_LoadUTF8(const int *codepoints, int length)
{
    // TODO: implement wrapper for LoadUTF8
    (void)codepoints;
    (void)length;
    // TODO: class C requires manual handling
    return NULL;
}

VrStereoConfig rl_LoadVrStereoConfig(VrDeviceInfo device)
{
    // TODO: implement wrapper for LoadVrStereoConfig
    (void)device;
    // TODO: class B requires manual handling
    return (VrStereoConfig){0};
}

Wave rl_LoadWave(const char *fileName)
{
    // TODO: implement wrapper for LoadWave
    (void)fileName;
    // TODO: class B requires manual handling
    return (Wave){0};
}

Wave rl_LoadWaveFromMemory(const char *fileType, const unsigned char *fileData, int dataSize)
{
    // TODO: implement wrapper for LoadWaveFromMemory
    (void)fileType;
    (void)fileData;
    (void)dataSize;
    // TODO: class C requires manual handling
    return (Wave){0};
}

float * rl_LoadWaveSamples(Wave wave)
{
    // TODO: implement wrapper for LoadWaveSamples
    (void)wave;
    // TODO: class B requires manual handling
    return NULL;
}

int rl_MakeDirectory(const char *dirPath)
{
    // TODO: implement wrapper for MakeDirectory
    (void)dirPath;
    return 0;
}

void rl_MaximizeWindow(void)
{
    // TODO: implement wrapper for MaximizeWindow
    return;
}

int rl_MeasureText(const char *text, int fontSize)
{
    // TODO: implement wrapper for MeasureText
    (void)text;
    (void)fontSize;
    return 0;
}

Vector2 rl_MeasureTextEx(Font font, const char *text, float fontSize, float spacing)
{
    // TODO: implement wrapper for MeasureTextEx
    (void)font;
    (void)text;
    (void)fontSize;
    (void)spacing;
    // TODO: class B requires manual handling
    return (Vector2){0};
}

void * rl_MemAlloc(unsigned int size)
{
    // TODO: implement wrapper for MemAlloc
    (void)size;
    // TODO: class B requires manual handling
    return NULL;
}

void rl_MemFree(void *ptr)
{
    // TODO: implement wrapper for MemFree
    (void)ptr;
    // TODO: class C requires manual handling
    return;
}

void * rl_MemRealloc(void *ptr, unsigned int size)
{
    // TODO: implement wrapper for MemRealloc
    (void)ptr;
    (void)size;
    // TODO: class C requires manual handling
    return NULL;
}

void rl_MinimizeWindow(void)
{
    // TODO: implement wrapper for MinimizeWindow
    return;
}

void rl_OpenURL(const char *url)
{
    // TODO: implement wrapper for OpenURL
    (void)url;
    return;
}

void rl_PauseAudioStream(AudioStream stream)
{
    // TODO: implement wrapper for PauseAudioStream
    (void)stream;
    // TODO: class B requires manual handling
    return;
}

void rl_PauseMusicStream(Music music)
{
    // TODO: implement wrapper for PauseMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_PauseSound(Sound sound)
{
    // TODO: implement wrapper for PauseSound
    (void)sound;
    // TODO: class B requires manual handling
    return;
}

void rl_PlayAudioStream(AudioStream stream)
{
    // TODO: implement wrapper for PlayAudioStream
    (void)stream;
    // TODO: class B requires manual handling
    return;
}

void rl_PlayAutomationEvent(AutomationEvent event)
{
    // TODO: implement wrapper for PlayAutomationEvent
    (void)event;
    // TODO: class B requires manual handling
    return;
}

void rl_PlayMusicStream(Music music)
{
    // TODO: implement wrapper for PlayMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_PlaySound(Sound sound)
{
    // TODO: implement wrapper for PlaySound
    (void)sound;
    // TODO: class B requires manual handling
    return;
}

void rl_PollInputEvents(void)
{
    // TODO: implement wrapper for PollInputEvents
    return;
}

void rl_RestoreWindow(void)
{
    // TODO: implement wrapper for RestoreWindow
    return;
}

void rl_ResumeAudioStream(AudioStream stream)
{
    // TODO: implement wrapper for ResumeAudioStream
    (void)stream;
    // TODO: class B requires manual handling
    return;
}

void rl_ResumeMusicStream(Music music)
{
    // TODO: implement wrapper for ResumeMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_ResumeSound(Sound sound)
{
    // TODO: implement wrapper for ResumeSound
    (void)sound;
    // TODO: class B requires manual handling
    return;
}

bool rl_SaveFileData(const char *fileName, void *data, int dataSize)
{
    // TODO: implement wrapper for SaveFileData
    (void)fileName;
    (void)data;
    (void)dataSize;
    // TODO: class C requires manual handling
    return false;
}

bool rl_SaveFileText(const char *fileName, const char *text)
{
    // TODO: implement wrapper for SaveFileText
    (void)fileName;
    (void)text;
    // TODO: class B requires manual handling
    return false;
}

void rl_SeekMusicStream(Music music, float position)
{
    // TODO: implement wrapper for SeekMusicStream
    (void)music;
    (void)position;
    // TODO: class B requires manual handling
    return;
}

void rl_SetAudioStreamBufferSizeDefault(int size)
{
    // TODO: implement wrapper for SetAudioStreamBufferSizeDefault
    (void)size;
    return;
}

void rl_SetAudioStreamCallback(AudioStream stream, AudioCallback callback)
{
    // TODO: implement wrapper for SetAudioStreamCallback
    (void)stream;
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetAudioStreamPan(AudioStream stream, float pan)
{
    // TODO: implement wrapper for SetAudioStreamPan
    (void)stream;
    (void)pan;
    // TODO: class B requires manual handling
    return;
}

void rl_SetAudioStreamPitch(AudioStream stream, float pitch)
{
    // TODO: implement wrapper for SetAudioStreamPitch
    (void)stream;
    (void)pitch;
    // TODO: class B requires manual handling
    return;
}

void rl_SetAudioStreamVolume(AudioStream stream, float volume)
{
    // TODO: implement wrapper for SetAudioStreamVolume
    (void)stream;
    (void)volume;
    // TODO: class B requires manual handling
    return;
}

void rl_SetAutomationEventBaseFrame(int frame)
{
    // TODO: implement wrapper for SetAutomationEventBaseFrame
    (void)frame;
    return;
}

void rl_SetAutomationEventList(AutomationEventList *list)
{
    // TODO: implement wrapper for SetAutomationEventList
    (void)list;
    // TODO: class C requires manual handling
    return;
}

void rl_SetClipboardText(const char *text)
{
    // TODO: implement wrapper for SetClipboardText
    (void)text;
    return;
}

void rl_SetConfigFlags(unsigned int flags)
{
    // TODO: implement wrapper for SetConfigFlags
    (void)flags;
    return;
}

void rl_SetExitKey(int key)
{
    // TODO: implement wrapper for SetExitKey
    (void)key;
    return;
}

int rl_SetGamepadMappings(const char *mappings)
{
    // TODO: implement wrapper for SetGamepadMappings
    (void)mappings;
    return 0;
}

void rl_SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration)
{
    // TODO: implement wrapper for SetGamepadVibration
    (void)gamepad;
    (void)leftMotor;
    (void)rightMotor;
    (void)duration;
    return;
}

void rl_SetGesturesEnabled(unsigned int flags)
{
    // TODO: implement wrapper for SetGesturesEnabled
    (void)flags;
    return;
}

void rl_SetLoadFileDataCallback(LoadFileDataCallback callback)
{
    // TODO: implement wrapper for SetLoadFileDataCallback
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetLoadFileTextCallback(LoadFileTextCallback callback)
{
    // TODO: implement wrapper for SetLoadFileTextCallback
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetMasterVolume(float volume)
{
    // TODO: implement wrapper for SetMasterVolume
    (void)volume;
    return;
}

void rl_SetMaterialTexture(Material *material, int mapType, Texture2D texture)
{
    // TODO: implement wrapper for SetMaterialTexture
    (void)material;
    (void)mapType;
    (void)texture;
    // TODO: class C requires manual handling
    return;
}

void rl_SetModelMeshMaterial(Model *model, int meshId, int materialId)
{
    // TODO: implement wrapper for SetModelMeshMaterial
    (void)model;
    (void)meshId;
    (void)materialId;
    // TODO: class C requires manual handling
    return;
}

void rl_SetMouseCursor(int cursor)
{
    // TODO: implement wrapper for SetMouseCursor
    (void)cursor;
    return;
}

void rl_SetMouseOffset(int offsetX, int offsetY)
{
    // TODO: implement wrapper for SetMouseOffset
    (void)offsetX;
    (void)offsetY;
    return;
}

void rl_SetMousePosition(int x, int y)
{
    // TODO: implement wrapper for SetMousePosition
    (void)x;
    (void)y;
    return;
}

void rl_SetMouseScale(float scaleX, float scaleY)
{
    // TODO: implement wrapper for SetMouseScale
    (void)scaleX;
    (void)scaleY;
    return;
}

void rl_SetMusicPan(Music music, float pan)
{
    // TODO: implement wrapper for SetMusicPan
    (void)music;
    (void)pan;
    // TODO: class B requires manual handling
    return;
}

void rl_SetMusicPitch(Music music, float pitch)
{
    // TODO: implement wrapper for SetMusicPitch
    (void)music;
    (void)pitch;
    // TODO: class B requires manual handling
    return;
}

void rl_SetMusicVolume(Music music, float volume)
{
    // TODO: implement wrapper for SetMusicVolume
    (void)music;
    (void)volume;
    // TODO: class B requires manual handling
    return;
}

void rl_SetPixelColor(void *dstPtr, Color color, int format)
{
    // TODO: implement wrapper for SetPixelColor
    (void)dstPtr;
    (void)color;
    (void)format;
    // TODO: class C requires manual handling
    return;
}

void rl_SetRandomSeed(unsigned int seed)
{
    // TODO: implement wrapper for SetRandomSeed
    (void)seed;
    return;
}

void rl_SetSaveFileDataCallback(SaveFileDataCallback callback)
{
    // TODO: implement wrapper for SetSaveFileDataCallback
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetSaveFileTextCallback(SaveFileTextCallback callback)
{
    // TODO: implement wrapper for SetSaveFileTextCallback
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetShaderValue(Shader shader, int locIndex, const void *value, int uniformType)
{
    // TODO: implement wrapper for SetShaderValue
    (void)shader;
    (void)locIndex;
    (void)value;
    (void)uniformType;
    // TODO: class C requires manual handling
    return;
}

void rl_SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat)
{
    // TODO: implement wrapper for SetShaderValueMatrix
    (void)shader;
    (void)locIndex;
    (void)mat;
    // TODO: class B requires manual handling
    return;
}

void rl_SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture)
{
    // TODO: implement wrapper for SetShaderValueTexture
    (void)shader;
    (void)locIndex;
    (void)texture;
    // TODO: class B requires manual handling
    return;
}

void rl_SetShaderValueV(Shader shader, int locIndex, const void *value, int uniformType, int count)
{
    // TODO: implement wrapper for SetShaderValueV
    (void)shader;
    (void)locIndex;
    (void)value;
    (void)uniformType;
    (void)count;
    // TODO: class C requires manual handling
    return;
}

void rl_SetShapesTexture(Texture2D texture, Rectangle source)
{
    // TODO: implement wrapper for SetShapesTexture
    (void)texture;
    (void)source;
    // TODO: class B requires manual handling
    return;
}

void rl_SetSoundPan(Sound sound, float pan)
{
    // TODO: implement wrapper for SetSoundPan
    (void)sound;
    (void)pan;
    // TODO: class B requires manual handling
    return;
}

void rl_SetSoundPitch(Sound sound, float pitch)
{
    // TODO: implement wrapper for SetSoundPitch
    (void)sound;
    (void)pitch;
    // TODO: class B requires manual handling
    return;
}

void rl_SetSoundVolume(Sound sound, float volume)
{
    // TODO: implement wrapper for SetSoundVolume
    (void)sound;
    (void)volume;
    // TODO: class B requires manual handling
    return;
}

void rl_SetTargetFPS(int fps)
{
    // TODO: implement wrapper for SetTargetFPS
    (void)fps;
    return;
}

void rl_SetTextLineSpacing(int spacing)
{
    // TODO: implement wrapper for SetTextLineSpacing
    (void)spacing;
    return;
}

void rl_SetTextureFilter(Texture2D texture, int filter)
{
    // TODO: implement wrapper for SetTextureFilter
    (void)texture;
    (void)filter;
    // TODO: class B requires manual handling
    return;
}

void rl_SetTextureWrap(Texture2D texture, int wrap)
{
    // TODO: implement wrapper for SetTextureWrap
    (void)texture;
    (void)wrap;
    // TODO: class B requires manual handling
    return;
}

void rl_SetTraceLogCallback(TraceLogCallback callback)
{
    // TODO: implement wrapper for SetTraceLogCallback
    (void)callback;
    // TODO: class D requires manual handling
    return;
}

void rl_SetTraceLogLevel(int logLevel)
{
    // TODO: implement wrapper for SetTraceLogLevel
    (void)logLevel;
    return;
}

void rl_SetWindowFocused(void)
{
    // TODO: implement wrapper for SetWindowFocused
    return;
}

void rl_SetWindowIcon(Image image)
{
    // TODO: implement wrapper for SetWindowIcon
    (void)image;
    // TODO: class B requires manual handling
    return;
}

void rl_SetWindowIcons(Image *images, int count)
{
    // TODO: implement wrapper for SetWindowIcons
    (void)images;
    (void)count;
    // TODO: class C requires manual handling
    return;
}

void rl_SetWindowMaxSize(int width, int height)
{
    // TODO: implement wrapper for SetWindowMaxSize
    (void)width;
    (void)height;
    return;
}

void rl_SetWindowMinSize(int width, int height)
{
    // TODO: implement wrapper for SetWindowMinSize
    (void)width;
    (void)height;
    return;
}

void rl_SetWindowMonitor(int monitor)
{
    // TODO: implement wrapper for SetWindowMonitor
    (void)monitor;
    return;
}

void rl_SetWindowOpacity(float opacity)
{
    // TODO: implement wrapper for SetWindowOpacity
    (void)opacity;
    return;
}

void rl_SetWindowPosition(int x, int y)
{
    // TODO: implement wrapper for SetWindowPosition
    (void)x;
    (void)y;
    return;
}

void rl_SetWindowSize(int width, int height)
{
    // TODO: implement wrapper for SetWindowSize
    (void)width;
    (void)height;
    return;
}

void rl_SetWindowState(unsigned int flags)
{
    // TODO: implement wrapper for SetWindowState
    (void)flags;
    return;
}

void rl_SetWindowTitle(const char *title)
{
    // TODO: implement wrapper for SetWindowTitle
    (void)title;
    return;
}

void rl_ShowCursor(void)
{
    // TODO: implement wrapper for ShowCursor
    return;
}

void rl_StartAutomationEventRecording(void)
{
    // TODO: implement wrapper for StartAutomationEventRecording
    return;
}

void rl_StopAudioStream(AudioStream stream)
{
    // TODO: implement wrapper for StopAudioStream
    (void)stream;
    // TODO: class B requires manual handling
    return;
}

void rl_StopAutomationEventRecording(void)
{
    // TODO: implement wrapper for StopAutomationEventRecording
    return;
}

void rl_StopMusicStream(Music music)
{
    // TODO: implement wrapper for StopMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_StopSound(Sound sound)
{
    // TODO: implement wrapper for StopSound
    (void)sound;
    // TODO: class B requires manual handling
    return;
}

void rl_SwapScreenBuffer(void)
{
    // TODO: implement wrapper for SwapScreenBuffer
    return;
}

void rl_TakeScreenshot(const char *fileName)
{
    // TODO: implement wrapper for TakeScreenshot
    (void)fileName;
    return;
}

void rl_TextAppend(char *text, const char *append, int *position)
{
    // TODO: implement wrapper for TextAppend
    (void)text;
    (void)append;
    (void)position;
    // TODO: class C requires manual handling
    return;
}

int rl_TextCopy(char *dst, const char *src)
{
    // TODO: implement wrapper for TextCopy
    (void)dst;
    (void)src;
    return 0;
}

int rl_TextFindIndex(const char *text, const char *search)
{
    // TODO: implement wrapper for TextFindIndex
    (void)text;
    (void)search;
    return 0;
}

const char * rl_TextFormat(const char *text, ...)
{
    // TODO: implement wrapper for TextFormat
    (void)text;
    // TODO: class D requires manual handling
    return NULL;
}

char * rl_TextInsert(const char *text, const char *insert, int position)
{
    // TODO: implement wrapper for TextInsert
    (void)text;
    (void)insert;
    (void)position;
    return NULL;
}

bool rl_TextIsEqual(const char *text1, const char *text2)
{
    // TODO: implement wrapper for TextIsEqual
    (void)text1;
    (void)text2;
    // TODO: class B requires manual handling
    return false;
}

char * rl_TextJoin(char **textList, int count, const char *delimiter)
{
    // TODO: implement wrapper for TextJoin
    (void)textList;
    (void)count;
    (void)delimiter;
    // TODO: class C requires manual handling
    return NULL;
}

unsigned int rl_TextLength(const char *text)
{
    // TODO: implement wrapper for TextLength
    (void)text;
    return 0;
}

const char * rl_TextRemoveSpaces(const char *text)
{
    // TODO: implement wrapper for TextRemoveSpaces
    (void)text;
    return NULL;
}

char * rl_TextReplace(const char *text, const char *search, const char *replacement)
{
    // TODO: implement wrapper for TextReplace
    (void)text;
    (void)search;
    (void)replacement;
    return NULL;
}

char * rl_TextReplaceBetween(const char *text, const char *begin, const char *end, const char *replacement)
{
    // TODO: implement wrapper for TextReplaceBetween
    (void)text;
    (void)begin;
    (void)end;
    (void)replacement;
    return NULL;
}

char ** rl_TextSplit(const char *text, char delimiter, int *count)
{
    // TODO: implement wrapper for TextSplit
    (void)text;
    (void)delimiter;
    (void)count;
    // TODO: class C requires manual handling
    return NULL;
}

const char * rl_TextSubtext(const char *text, int position, int length)
{
    // TODO: implement wrapper for TextSubtext
    (void)text;
    (void)position;
    (void)length;
    return NULL;
}

char * rl_TextToCamel(const char *text)
{
    // TODO: implement wrapper for TextToCamel
    (void)text;
    return NULL;
}

float rl_TextToFloat(const char *text)
{
    // TODO: implement wrapper for TextToFloat
    (void)text;
    return 0;
}

int rl_TextToInteger(const char *text)
{
    // TODO: implement wrapper for TextToInteger
    (void)text;
    return 0;
}

char * rl_TextToLower(const char *text)
{
    // TODO: implement wrapper for TextToLower
    (void)text;
    return NULL;
}

char * rl_TextToPascal(const char *text)
{
    // TODO: implement wrapper for TextToPascal
    (void)text;
    return NULL;
}

char * rl_TextToSnake(const char *text)
{
    // TODO: implement wrapper for TextToSnake
    (void)text;
    return NULL;
}

char * rl_TextToUpper(const char *text)
{
    // TODO: implement wrapper for TextToUpper
    (void)text;
    return NULL;
}

void rl_ToggleBorderlessWindowed(void)
{
    // TODO: implement wrapper for ToggleBorderlessWindowed
    return;
}

void rl_ToggleFullscreen(void)
{
    // TODO: implement wrapper for ToggleFullscreen
    return;
}

void rl_TraceLog(int logLevel, const char *text, ...)
{
    // TODO: implement wrapper for TraceLog
    (void)logLevel;
    (void)text;
    // TODO: class D requires manual handling
    return;
}

void rl_UnloadAudioStream(AudioStream stream)
{
    // TODO: implement wrapper for UnloadAudioStream
    (void)stream;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadAutomationEventList(AutomationEventList list)
{
    // TODO: implement wrapper for UnloadAutomationEventList
    (void)list;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadCodepoints(int *codepoints)
{
    // TODO: implement wrapper for UnloadCodepoints
    (void)codepoints;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadDirectoryFiles(FilePathList files)
{
    // TODO: implement wrapper for UnloadDirectoryFiles
    (void)files;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadDroppedFiles(FilePathList files)
{
    // TODO: implement wrapper for UnloadDroppedFiles
    (void)files;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadFileData(unsigned char *data)
{
    // TODO: implement wrapper for UnloadFileData
    (void)data;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadFileText(char *text)
{
    // TODO: implement wrapper for UnloadFileText
    (void)text;
    return;
}

void rl_UnloadFont(Font font)
{
    // TODO: implement wrapper for UnloadFont
    (void)font;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadFontData(GlyphInfo *glyphs, int glyphCount)
{
    // TODO: implement wrapper for UnloadFontData
    (void)glyphs;
    (void)glyphCount;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadImage(Image image)
{
    // TODO: implement wrapper for UnloadImage
    (void)image;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadImageColors(Color *colors)
{
    // TODO: implement wrapper for UnloadImageColors
    (void)colors;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadImagePalette(Color *colors)
{
    // TODO: implement wrapper for UnloadImagePalette
    (void)colors;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadMaterial(Material material)
{
    // TODO: implement wrapper for UnloadMaterial
    (void)material;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadMesh(Mesh mesh)
{
    // TODO: implement wrapper for UnloadMesh
    (void)mesh;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadModel(Model model)
{
    // TODO: implement wrapper for UnloadModel
    (void)model;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadModelAnimation(ModelAnimation anim)
{
    // TODO: implement wrapper for UnloadModelAnimation
    (void)anim;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadModelAnimations(ModelAnimation *animations, int animCount)
{
    // TODO: implement wrapper for UnloadModelAnimations
    (void)animations;
    (void)animCount;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadMusicStream(Music music)
{
    // TODO: implement wrapper for UnloadMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadRandomSequence(int *sequence)
{
    // TODO: implement wrapper for UnloadRandomSequence
    (void)sequence;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadRenderTexture(RenderTexture2D target)
{
    // TODO: implement wrapper for UnloadRenderTexture
    (void)target;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadShader(Shader shader)
{
    // TODO: implement wrapper for UnloadShader
    (void)shader;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadSound(Sound sound)
{
    // TODO: implement wrapper for UnloadSound
    (void)sound;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadSoundAlias(Sound alias)
{
    // TODO: implement wrapper for UnloadSoundAlias
    (void)alias;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadTextLines(char **text, int lineCount)
{
    // TODO: implement wrapper for UnloadTextLines
    (void)text;
    (void)lineCount;
    // TODO: class C requires manual handling
    return;
}

void rl_UnloadTexture(Texture2D texture)
{
    // TODO: implement wrapper for UnloadTexture
    (void)texture;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadUTF8(char *text)
{
    // TODO: implement wrapper for UnloadUTF8
    (void)text;
    return;
}

void rl_UnloadVrStereoConfig(VrStereoConfig config)
{
    // TODO: implement wrapper for UnloadVrStereoConfig
    (void)config;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadWave(Wave wave)
{
    // TODO: implement wrapper for UnloadWave
    (void)wave;
    // TODO: class B requires manual handling
    return;
}

void rl_UnloadWaveSamples(float *samples)
{
    // TODO: implement wrapper for UnloadWaveSamples
    (void)samples;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateAudioStream(AudioStream stream, const void *data, int frameCount)
{
    // TODO: implement wrapper for UpdateAudioStream
    (void)stream;
    (void)data;
    (void)frameCount;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateCamera(Camera *camera, int mode)
{
    // TODO: implement wrapper for UpdateCamera
    (void)camera;
    (void)mode;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateCameraPro(Camera *camera, Vector3 movement, Vector3 rotation, float zoom)
{
    // TODO: implement wrapper for UpdateCameraPro
    (void)camera;
    (void)movement;
    (void)rotation;
    (void)zoom;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateMeshBuffer(Mesh mesh, int index, const void *data, int dataSize, int offset)
{
    // TODO: implement wrapper for UpdateMeshBuffer
    (void)mesh;
    (void)index;
    (void)data;
    (void)dataSize;
    (void)offset;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateModelAnimation(Model model, ModelAnimation anim, int frame)
{
    // TODO: implement wrapper for UpdateModelAnimation
    (void)model;
    (void)anim;
    (void)frame;
    // TODO: class B requires manual handling
    return;
}

void rl_UpdateModelAnimationBones(Model model, ModelAnimation anim, int frame)
{
    // TODO: implement wrapper for UpdateModelAnimationBones
    (void)model;
    (void)anim;
    (void)frame;
    // TODO: class B requires manual handling
    return;
}

void rl_UpdateMusicStream(Music music)
{
    // TODO: implement wrapper for UpdateMusicStream
    (void)music;
    // TODO: class B requires manual handling
    return;
}

void rl_UpdateSound(Sound sound, const void *data, int sampleCount)
{
    // TODO: implement wrapper for UpdateSound
    (void)sound;
    (void)data;
    (void)sampleCount;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateTexture(Texture2D texture, const void *pixels)
{
    // TODO: implement wrapper for UpdateTexture
    (void)texture;
    (void)pixels;
    // TODO: class C requires manual handling
    return;
}

void rl_UpdateTextureRec(Texture2D texture, Rectangle rec, const void *pixels)
{
    // TODO: implement wrapper for UpdateTextureRec
    (void)texture;
    (void)rec;
    (void)pixels;
    // TODO: class C requires manual handling
    return;
}

void rl_UploadMesh(Mesh *mesh, bool dynamic)
{
    // TODO: implement wrapper for UploadMesh
    (void)mesh;
    (void)dynamic;
    // TODO: class C requires manual handling
    return;
}

void rl_WaitTime(double seconds)
{
    // TODO: implement wrapper for WaitTime
    (void)seconds;
    return;
}

Wave rl_WaveCopy(Wave wave)
{
    // TODO: implement wrapper for WaveCopy
    (void)wave;
    // TODO: class B requires manual handling
    return (Wave){0};
}

void rl_WaveCrop(Wave *wave, int initFrame, int finalFrame)
{
    // TODO: implement wrapper for WaveCrop
    (void)wave;
    (void)initFrame;
    (void)finalFrame;
    // TODO: class C requires manual handling
    return;
}

void rl_WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels)
{
    // TODO: implement wrapper for WaveFormat
    (void)wave;
    (void)sampleRate;
    (void)sampleSize;
    (void)channels;
    // TODO: class C requires manual handling
    return;
}

bool rl_WindowShouldClose(void)
{
    // TODO: implement wrapper for WindowShouldClose
    // TODO: class B requires manual handling
    return false;
}
