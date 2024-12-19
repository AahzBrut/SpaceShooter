#include "enemy/TweenBlade.h"

#include "weapon/BulletShooter.h"


namespace SpaceShooter {
    using enum CollisionLayers;

    TweenBlade::TweenBlade(World *world, const std::string &texturePath, const Vector2 &velocity)
        : EnemySpaceShip(world, texturePath),
          leftBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player | PlayerBullet}},
          rightBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player | PlayerBullet}} {
        {
            SetRewardAmount(150);
            SetRotation(90);
            CenterPivotOffset();
            SetVelocity(velocity);

            leftBulletShooter->SetMuzzleOffset(Vector2{-20, 30});
            leftBulletShooter->SetMuzzleRotation(15);
            rightBulletShooter->SetMuzzleOffset(Vector2{20, 30});
            rightBulletShooter->SetMuzzleRotation(-15);
        }
    }

    void TweenBlade::Shoot() {
        leftBulletShooter->Shoot();
        rightBulletShooter->Shoot();
    }

    void TweenBlade::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);

        Shoot();
    }
}
