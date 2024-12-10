#pragma once
#include "EnemySpaceShip.h"
#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    class BulletShooter;

    class Vanguard final : public EnemySpaceShip {
    public:
        explicit Vanguard(World *world,
                          const std::string &texturePath = "assets/SpaceShooterRedux/PNG/Enemies/enemyBlue3.png",
                          const Vector2& velocity = Vector2{0,100});
        void Shoot() override;
        void Update(float deltaTime) override;

    private:
        Unique<BulletShooter> bulletShooter;
    };
}
