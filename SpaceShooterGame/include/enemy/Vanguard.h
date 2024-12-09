#pragma once
#include "EnemySpaceShip.h"

namespace SpaceShooter {
    class BulletShooter;

    class Vanguard : public EnemySpaceShip {
    public:
        explicit Vanguard(World *world,
                          const std::string &texturePath = "assets/SpaceShooterRedux/PNG/Enemies/enemyBlue3.png",
                          const Vector2& velocity = Vector2{0,50});
        void Shoot() override;
        void Update(float deltaTime) override;

    private:
        Unique<BulletShooter> bulletShooter;
    };
}
