#pragma once
#include <raylib.h>


namespace SpaceShooter {
    class Transform {
    public:
        Transform() = default;

        Vector2 position{0, 0};
        float rotation{0};
        float scale{0};
    };
}
