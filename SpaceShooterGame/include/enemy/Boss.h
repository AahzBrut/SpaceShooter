#pragma once
#include "EnemySpaceShip.h"


namespace SpaceShooter {
    class BulletShooter;
    class ThreeWayShooter;
    class FrontalWiper;

    class Boss final : public EnemySpaceShip {
    public:
        explicit Boss(World *world);
        void Update(float deltaTime) override;
        void Shoot() override;
        void Initialize() override;

    private:
        float speed{100};
        float switchDistance{100};
        Unique<BulletShooter> leftShooter;
        Unique<BulletShooter> rightShooter;
        Unique<ThreeWayShooter> threeWayShooterLeft;
        Unique<ThreeWayShooter> threeWayShooterRight;
        Unique<FrontalWiper> frontalWiper;
        int stage{1};

        void SideMovement();
        void OnHealthChanged(float amount, float health, float maxHealth);
        void SetStage(int newStage);
    };
}
