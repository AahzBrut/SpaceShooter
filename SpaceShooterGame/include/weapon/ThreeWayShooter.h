#pragma once
#include "BulletShooter.h"
#include "Shooter.h"

namespace SpaceShooter {
    class ThreeWayShooter : public Shooter {
    public:
        explicit ThreeWayShooter(Actor* actor, float coolDownTime = 0.3f, const Vector2& localOffset = {0, 0});

    private:
        BulletShooter leftShooter;
        BulletShooter centerShooter;
        BulletShooter rightShooter;

        void ShootImpl() override;
    };
}
