#pragma once

namespace SpaceShooter {
    class HealthComponent {
        public:
        HealthComponent(float health, float maxHealth);

        void ChangeHealth(float amount);

        [[nodiscard]] float GetHealth() const { return health; }
        [[nodiscard]] float GetMaxHealth() const { return maxHealth; }

    private:
        void DamageTaken(float amount);
        void HealthEmpty();
        void HealthRegenerated(float amount);
        float health;
        float maxHealth;
    };
}