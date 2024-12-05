#pragma once
#include "Shooter.h"

namespace SpaceShooter {
    class BulletShooter: public Shooter {
    public:
        explicit BulletShooter(Actor* owner, float coolDownTimeout = 1.f);
        bool IsOnCooldown() override;

    private:
        float coolDownTimeout;
        float lastShootTime{0};
        void ShootImpl() override;
    };
}
