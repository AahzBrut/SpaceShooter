#pragma once
#include "EnemySpaceShip.h"

namespace SpaceShooter {
    class BulletShooter;

    class TweenBlade final : public EnemySpaceShip {
    public:
        explicit TweenBlade(World *world,
                            const std::string &texturePath = "assets/SpaceShooterRedux/PNG/Enemies/enemyBlack1.png",
                            const Vector2 &velocity = Vector2{0, 110});
        void Shoot() override;
        void Update(float deltaTime) override;

    private:
        Unique<BulletShooter> leftBulletShooter;
        Unique<BulletShooter> rightBulletShooter;
    };
}
