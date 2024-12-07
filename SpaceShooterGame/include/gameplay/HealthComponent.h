#pragma once
#include "framework/Delegate.h"

namespace SpaceShooter {
    class HealthComponent {
        public:
        HealthComponent(float health, float maxHealth);

        void ChangeHealth(float amount);

        [[nodiscard]] float GetHealth() const { return health; }
        [[nodiscard]] float GetMaxHealth() const { return maxHealth; }

        Delegate<float, float, float> HealthChanged;
        Delegate<float, float, float> DamageTaken;
        Delegate<float, float, float> HealthRegenerated;
        Delegate<> Death;

    private:
        void TakeDamage(float amount);
        void HealthEmpty();
        void RegenerateHealth(float amount);
        float health;
        float maxHealth;
    };
}
