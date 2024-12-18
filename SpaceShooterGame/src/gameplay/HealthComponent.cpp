#include "gameplay/HealthComponent.h"

namespace SpaceShooter {
    HealthComponent::HealthComponent(const float health, const float maxHealth) : health{health}, maxHealth{maxHealth} {
    }

    void HealthComponent::ChangeHealth(const float amount) {
        if (amount == 0 || health == 0) return;
        health -= amount;

        if (health > maxHealth) {
            health = maxHealth;
        }

        if (health <= 0) {
            health = 0;
            HealthEmpty();
        } else {
            HealthChanged.Emit(amount, GetHealth(), GetMaxHealth());
        }

        if (amount > 0) {
            TakeDamage(amount);
        } else {
            RegenerateHealth(amount);
        }
    }

    void HealthComponent::TakeDamage(const float amount) {
        DamageTaken.Emit(amount, health, maxHealth);
    }

    void HealthComponent::HealthEmpty() {
        Death.Emit();
    }

    void HealthComponent::RegenerateHealth(const float amount) {
        LOG("Regenerating health");
        HealthRegenerated.Emit(amount, health, maxHealth);
    }
}
