#pragma once
#include "Shooter.h"

namespace SpaceShooter {
    class BulletShooter : public Shooter {
    public:
        explicit BulletShooter(Actor *owner, float coolDownTimeout = 1.f,
                               CollisionLayers bulletLayer = CollisionLayers::None,
                               CollisionLayers bulletMaskLayer = CollisionLayers::None);
        bool IsOnCooldown() override;

        void SetMuzzleOffset(const Vector2 &offset) { muzzleOffset = offset; }
        void SetMuzzleRotation(const float rotation) { muzzleRotation = rotation; }
        void SetBulletTexture(const std::string &path) { bulletTexturePath = path; }

    private:
        Vector2 muzzleOffset{};
        float muzzleRotation{};
        float coolDownTimeout;
        float lastShootTime{0};
        CollisionLayers bulletLayer;
        CollisionLayers bulletMaskLayer;
        std::string bulletTexturePath;

        void ShootImpl() override;
    };
}
