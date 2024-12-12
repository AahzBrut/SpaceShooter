#pragma once
#include "EnemySpaceShip.h"


namespace SpaceShooter {
    class BulletShooter;

    class UFO final : public EnemySpaceShip {
    public:
        explicit UFO(World *world,
                     const std::string &texturePath = "assets/SpaceShooterRedux/PNG/ufoBlue.png",
                     const Vector2 &velocity = Vector2{0, 0});
        void Update(float deltaTime) override;

    private:
        Unique<BulletShooter> shooter1;
        Unique<BulletShooter> shooter2;
        Unique<BulletShooter> shooter3;
        float rotationSpeed{15};

        void Shoot() override;
    };
}
