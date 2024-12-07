#pragma once
#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"


namespace SpaceShooter {
    class SpaceShip : public Actor {
    public:
        explicit SpaceShip(World *world, const std::string &texturePath = "",
                           CollisionLayers selfCollisionLayers = CollisionLayers::None,
                           CollisionLayers contactCollisionLayers = CollisionLayers::None);
        void Update(float deltaTime) override;
        void Initialize() override;
        void SetVelocity(const Vector2 &velocity);
        [[nodiscard]] Vector2 GetVelocity() const { return velocity; }

        void OnContactBegin(Actor *actor) override;
        virtual void Shoot();

    private:
        Vector2 velocity{};
        HealthComponent healthComponent{100, 100};

        virtual void OnDamageTaken(float amount, float health, float maxHealth);
        virtual void OnDeath();
    };
}
