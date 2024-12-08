#pragma once
#include "framework/World.h"

namespace SpaceShooter {
    class Explosion {
    public:
        explicit Explosion(
            int particleAmount = 20,
            float lifeTimeMin = 0.5f,
            float lifeTimeMax = 1.5f,
            float sizeMin = 1,
            float sizeMax = 3,
            float speedMin = 200,
            float speedMax = 400,
            const Color& color = {255, 128, 0, 255},
            const List<std::string>& particleImagePaths = {
                "assets/SpaceShooterRedux/PNG/Effects/star1.png",
                "assets/SpaceShooterRedux/PNG/Effects/star2.png",
                "assets/SpaceShooterRedux/PNG/Effects/star3.png",
            }
        );

        void Spawn(World *world, const Vector2& position) const;

    private:
        int particleAmount;
        float lifeTimeMin;
        float lifeTimeMax;
        float sizeMin;
        float sizeMax;
        float speedMin;
        float speedMax;
        Color color;
        List<std::string> particleImagePaths;
    };
}
