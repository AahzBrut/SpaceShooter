#pragma once
#include "Shooter.h"

namespace SpaceShooter {
    class BulletShooter: public Shooter {
    public:
        explicit BulletShooter(Actor* owner, float coolDownTimeout = 1.f, CollisionLayers bulletLayer = CollisionLayers::None, CollisionLayers bulletMaskLayer = CollisionLayers::None);
        bool IsOnCooldown() override;

    private:
        float coolDownTimeout;
        float lastShootTime{0};
        CollisionLayers bulletLayer;
        CollisionLayers bulletMaskLayer;

        void ShootImpl() override;
    };
}
