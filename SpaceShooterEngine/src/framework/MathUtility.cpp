#include <cmath>
#include "framework/MathUtility.h"


namespace SpaceShooter {
    Vector2 RotationToVector(const float rotation) {
        const auto radians = DegreesToRadians(rotation);
        return Vector2(cos(radians), sin(radians)); // NOLINT(*-narrowing-conversions)
    }

    float DegreesToRadians(const float degrees) {
        return degrees * PI / 180.f;
    }

    float RadiansToDegrees(const float radians) {
        return radians * 180.f / PI;
    }

    float LerpFloat(const float a, const float b, float alfa) {
        alfa = alfa > 1 ? 1 : alfa < 0 ? 0 : alfa;
        return a + (b - a) * alfa;
    }

    Color LerpColor(const Color &a, const Color &b, const float alfa) {
        const auto red = static_cast<int>(LerpFloat(a.r, b.r, alfa));
        const auto green = static_cast<int>(LerpFloat(a.g, b.g, alfa));
        const auto blue = static_cast<int>(LerpFloat(a.b, b.b, alfa));
        const auto alpha = static_cast<int>(LerpFloat(a.a, b.a, alfa));
        return Color(red, green, blue, alpha);
    }

    Vector2 LerpVector(const Vector2 &a, const Vector2 &b, const float alfa) {
        const auto lerpX = LerpFloat(a.x, b.x, alfa);
        const auto lerpY = LerpFloat(a.y, b.y, alfa);
        return Vector2(lerpX, lerpY);
    }
}
