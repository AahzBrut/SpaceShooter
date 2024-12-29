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
        void SetDestructionSound(const std::string &soundPath);

        void Blink();
        void UpdateBlink(float deltaTime);
        virtual void ApplyDamage(float amount);
        HealthComponent &GetHealthComponent() { return healthComponent; }

        void OnContactBegin(Actor *actor) override;
        virtual void Shoot() {}

    protected:
        virtual void OnDamageTaken(float amount, float health, float maxHealth);
        virtual void OnDeath();

    private:
        Vector2 velocity{};
        HealthComponent healthComponent{100, 100};
        float blinkTime{0};
        float blinkDuration{0.15f};
        Color blinkColorOffset{255, 0, 0, 255};
        Shared<Sound> destructionSound{nullptr};
    };
}
