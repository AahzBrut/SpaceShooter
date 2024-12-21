#pragma once
#include "BulletShooter.h"
#include "Shooter.h"

namespace SpaceShooter {
    class ThreeWayShooter final : public Shooter {
    public:
        explicit ThreeWayShooter(Actor* actor, float coolDownTime = 0.3f, const Vector2& localOffset = {0, 0});

        void IncreaseLevel(int amount) override;
        void SetLevel(int amount) override;
        void SetLayers(CollisionLayers selfLayer, CollisionLayers otherLayer);

    private:
        BulletShooter leftShooter;
        BulletShooter centerShooter;
        BulletShooter rightShooter;

        BulletShooter topLevelLeftShooter;
        BulletShooter topLevelRightShooter;

        void ShootImpl() override;
    };
}
