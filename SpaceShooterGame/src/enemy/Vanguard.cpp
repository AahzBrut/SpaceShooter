#include "enemy/Vanguard.h"

#include "weapon/BulletShooter.h"


namespace SpaceShooter {
    using enum CollisionLayers;

    Vanguard::Vanguard(World *world, const std::string &texturePath, const Vector2 &velocity)
        : EnemySpaceShip(world, texturePath),
          bulletShooter{new BulletShooter{this, 1, EnemyBullet, Player | PlayerBullet}} {
        SetRewardAmount(100);
        SetRotation(90);
        CenterPivotOffset();
        SetVelocity(velocity);
        bulletShooter->SetMuzzleOffset(Vector2{0, 30});
    }

    void Vanguard::Shoot() {
        bulletShooter->Shoot();
    }

    void Vanguard::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);
        Shoot();
    }
}
