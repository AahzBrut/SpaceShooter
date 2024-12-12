#include "enemy/Hexagon.h"

#include "weapon/BulletShooter.h"

using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    Hexagon::Hexagon(World *world, const std::string &texturePath, const Vector2 &velocity)
        : EnemySpaceShip(world, texturePath),
          forwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}},
          leftForwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}},
          rightForwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}},
          leftBackwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}},
          rightBackwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}},
          backwardBulletShooter{new BulletShooter{this, 1, EnemyBullet, Player}} {
        SetRotation(90);
        CenterPivotOffset();
        SetVelocity(velocity);

        forwardBulletShooter->SetMuzzleOffset(Vector2{0, 50});
        forwardBulletShooter->SetMuzzleRotation(0);
        leftForwardBulletShooter->SetMuzzleOffset(Vector2{40, 40});
        leftForwardBulletShooter->SetMuzzleRotation(-30);
        rightForwardBulletShooter->SetMuzzleOffset(Vector2{-40, 40});
        rightForwardBulletShooter->SetMuzzleRotation(30);
        leftBackwardBulletShooter->SetMuzzleOffset(Vector2{40, -40});
        leftBackwardBulletShooter->SetMuzzleRotation(-150);
        rightBackwardBulletShooter->SetMuzzleOffset(Vector2{-40, -40});
        rightBackwardBulletShooter->SetMuzzleRotation(150);
        backwardBulletShooter->SetMuzzleOffset(Vector2{0, -50});
        backwardBulletShooter->SetMuzzleRotation(180);
    }

    void Hexagon::Shoot() {
        forwardBulletShooter.get()->Shoot();
        leftForwardBulletShooter.get()->Shoot();
        rightForwardBulletShooter.get()->Shoot();
        leftBackwardBulletShooter.get()->Shoot();
        rightBackwardBulletShooter.get()->Shoot();
        backwardBulletShooter.get()->Shoot();
    }

    void Hexagon::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);

        Shoot();
    }
}
