#pragma once
#include "EnemySpaceShip.h"
#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    class Hexagon final : public EnemySpaceShip {
    public:
        explicit Hexagon(World *world,
                            const std::string &texturePath = "assets/SpaceShooterRedux/PNG/Enemies/enemyGreen4.png",
                            const Vector2 &velocity = Vector2{0, 70});
        void Shoot() override;
        void Update(float deltaTime) override;

    private:
        Unique<BulletShooter> forwardBulletShooter;
        Unique<BulletShooter> leftForwardBulletShooter;
        Unique<BulletShooter> rightForwardBulletShooter;
        Unique<BulletShooter> leftBackwardBulletShooter;
        Unique<BulletShooter> rightBackwardBulletShooter;
        Unique<BulletShooter> backwardBulletShooter;
    };
}
