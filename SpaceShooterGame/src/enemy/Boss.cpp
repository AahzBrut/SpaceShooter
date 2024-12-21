#include "enemy/Boss.h"

#include "weapon/BulletShooter.h"
using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    Boss::Boss(World *world)
        : EnemySpaceShip{world, "assets/SpaceShooterRedux/PNG/Boss.png"},
          leftShooter{new BulletShooter{this, 1, EnemyBullet, Player | PlayerBullet}},
          rightShooter{new BulletShooter{this, 1, EnemyBullet, Player | PlayerBullet}} {
        SetRotation(90);
        CenterPivotOffset();
        SetVelocity({speed, 0});
        SetRewardChance(0);
        GetHealthComponent().SetInitialHealth(3000);

        leftShooter->SetMuzzleOffset({-50, 50});
        rightShooter->SetMuzzleOffset({50, 50});
    }

    void Boss::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);
        SideMovement();
        Shoot();
    }

    void Boss::Shoot() {
        EnemySpaceShip::Shoot();
        leftShooter->Shoot();
        rightShooter->Shoot();
    }

    void Boss::SideMovement() {
        const auto posX = GetTransform().position.x;
        if (const auto bossWidth = GetSize().x; posX > GetWorld()->GetWindowSize().x - bossWidth * 0.5f) {
            SetVelocity({-speed, 0});
        } else if (posX < bossWidth * 0.5f) {
            SetVelocity({speed, 0});
        }
    }
}
