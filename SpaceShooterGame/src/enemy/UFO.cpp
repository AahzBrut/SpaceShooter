#include "enemy/UFO.h"

#include "weapon/BulletShooter.h"


namespace SpaceShooter {
    using enum CollisionLayers;

    UFO::UFO(World *world, const std::string &texturePath, const Vector2 &velocity)
        : EnemySpaceShip(world, texturePath),
          shooter1{new BulletShooter{this, .5f, EnemyBullet, Player | PlayerBullet}},
          shooter2{new BulletShooter{this, .5f, EnemyBullet, Player | PlayerBullet}},
          shooter3{new BulletShooter{this, .5f, EnemyBullet, Player | PlayerBullet}} {
        SetRewardAmount(300);
        SetRotation(90);
        CenterPivotOffset();
        SetVelocity(velocity);

        shooter1->SetMuzzleRotation(-60);
        shooter2->SetMuzzleRotation(60);
        shooter3->SetMuzzleRotation(180);
    }

    void UFO::Shoot() {
        shooter1->Shoot();
        shooter2->Shoot();
        shooter3->Shoot();
    }

    void UFO::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);

        Shoot();
        SetRotationOffset(rotationSpeed * deltaTime);
    }
}
