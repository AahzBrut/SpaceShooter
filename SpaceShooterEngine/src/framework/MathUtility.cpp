#include "framework/MathUtility.h"

#include <cmath>
#include <random>


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

    float RandomRange(const float min, const float max) {
        std::random_device rd;
        std::mt19937 gen(rd()); // NOLINT(*-narrowing-conversions)
        std::uniform_real_distribution distribution(min, max);
        return distribution(gen);
    }

    Vector2 RandomUnitVector() {
        const auto randomX = RandomRange(-1, 1);
        const auto randomY = RandomRange(-1, 1);
        auto length = std::sqrt(randomX * randomX + randomY * randomY);
        length = length == 0 ? 0.00001f : length;
        return Vector2(randomX / length, randomY / length);
    }

    void NormalizeVector(Vector2 &vector) {
        auto length = VectorLength(vector);
        if (length == 0.0f) {length = 0.00001f;}
        vector.x /= length;
        vector.y /= length;
    }

    float VectorLength(const Vector2 &vector) {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
    }
}
