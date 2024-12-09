#include "enemy/Vanguard.h"
#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    Vanguard::Vanguard(World *world, const std::string &texturePath, const Vector2 &velocity)
        : EnemySpaceShip(world, texturePath),
          bulletShooter{new BulletShooter{this, 1, CollisionLayers::EnemyBullet, CollisionLayers::Player}} {
        SetRotation(90);
        CenterPivotOffset();
        SetVelocity(velocity);
    }

    void Vanguard::Shoot() {
        bulletShooter->Shoot();
    }

    void Vanguard::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);
        Shoot();
    }
}
