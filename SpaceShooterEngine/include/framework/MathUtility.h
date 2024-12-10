#pragma once
#include <raylib.h>

namespace SpaceShooter {
    Vector2 RotationToVector(float rotation);
    float DegreesToRadians(float degrees);
    float RadiansToDegrees(float radians);
    float LerpFloat(float a, float b, float alfa);
    Color LerpColor(const Color& a, const Color& b, float alfa);
    Vector2 LerpVector(const Vector2& a, const Vector2& b, float alfa);
    float RandomRange(float min, float max);
    Vector2 RandomUnitVector();
}
