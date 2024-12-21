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
        leftShooter->Shoot();
        rightShooter->Shoot();
    }

    void Boss::Initialize() {
        EnemySpaceShip::Initialize();
        GetHealthComponent().HealthChanged.BindAction(GetWeakRef(), &Boss::OnHealthChanged);
    }

    void Boss::SideMovement() {
        const auto posX = GetTransform().position.x;
        if (const auto bossWidth = GetSize().x; posX > GetWorld()->GetWindowSize().x - bossWidth * 0.5f) {
            SetVelocity({-speed, 0});
        } else if (posX < bossWidth * 0.5f) {
            SetVelocity({speed, 0});
        }
    }

    void Boss::OnHealthChanged([[maybe_unused]] float amount, const float health, const float maxHealth) {
        if (const auto healthPercent = health / maxHealth; healthPercent > .4 && healthPercent <= .7) {
            SetStage(2);
        } else if (healthPercent > .1 && healthPercent <= .4 ) {
            SetStage(3);
        } else if (healthPercent <= .1) {
            SetStage(4);
        }
    }

    // ReSharper disable once CppDFAUnreachableFunctionCall
    void Boss::SetStage(const int newStage) {
        stage = newStage;
        frontalWiper->SetLevel(newStage);
        threeWayShooterLeft->SetLevel(newStage);
        threeWayShooterRight->SetLevel(newStage);
    }
}
