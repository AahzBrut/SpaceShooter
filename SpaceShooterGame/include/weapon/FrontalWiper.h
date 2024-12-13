#pragma once
#include "BulletShooter.h"

namespace SpaceShooter {
    class FrontalWiper final : public Shooter {
    public:
        explicit FrontalWiper(Actor *actor, float coolDownTime = 0.3f, const Vector2& offsetPosition = {0,0});

    private:
        BulletShooter shooter1;
        BulletShooter shooter2;
        BulletShooter shooter3;
        BulletShooter shooter4;

        void ShootImpl() override;
    };
}
