#pragma once
#include "EnemySpaceShip.h"


namespace SpaceShooter {
    class BulletShooter;

    class Boss final : public EnemySpaceShip {
    public:
        explicit Boss(World *world);
        void Update(float deltaTime) override;
        void Shoot() override;

    private:
        float speed{100};
        float switchDistance{100};
        Unique<BulletShooter> leftShooter;
        Unique<BulletShooter> rightShooter;

        void SideMovement();
    };
}
