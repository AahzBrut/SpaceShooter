#pragma once
#include "BulletShooter.h"

namespace SpaceShooter {
    class FrontalWiper final : public Shooter {
    public:
        explicit FrontalWiper(Actor *actor, float coolDownTime = 0.3f, const Vector2 &offsetPosition = {0, 0});

        void IncreaseLevel(int amount) override;
        void SetLevel(int amount) override;
        void SetLayers(CollisionLayers selfLayer, CollisionLayers otherLayer);

    private:
        BulletShooter shooter1;
        BulletShooter shooter2;
        BulletShooter shooter3;
        BulletShooter shooter4;
        BulletShooter shooter5;
        BulletShooter shooter6;

        void ShootImpl() override;
    };
}
