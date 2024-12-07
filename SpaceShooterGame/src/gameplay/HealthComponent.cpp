#include "gameplay/HealthComponent.h"
#include "framework/Core.h"

namespace SpaceShooter {
    HealthComponent::HealthComponent(const float health, const float maxHealth) : health{health}, maxHealth{maxHealth} {
    }

    void HealthComponent::ChangeHealth(const float amount) {
        if (amount == 0 || health == 0) return;
        health -= amount;

        if (health < 0) {
            health = 0;
            HealthEmpty();
        }
        if (health > maxHealth) {
            health = maxHealth;
        }

        if (amount > 0) {
            DamageTaken(amount);
        } else {
            HealthRegenerated(amount);
        }
    }

    void HealthComponent::DamageTaken(const float amount) {
        LOG("Damage taken: %f (%f/%f)", amount, health, maxHealth);
    }

    void HealthComponent::HealthEmpty() {
        LOG("Health is empty");
    }

    void HealthComponent::HealthRegenerated(const float amount) {
        LOG("Health regenerated: %f, (%f/%f)", amount,  health, maxHealth);
    }
}
