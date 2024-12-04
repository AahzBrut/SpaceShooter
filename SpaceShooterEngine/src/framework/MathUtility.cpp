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
}
