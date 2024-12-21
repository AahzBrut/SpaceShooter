#include "weapon/Shooter.h"

namespace SpaceShooter {
    void Shooter::IncreaseLevel(const int amount) {
        if (currentLevel + amount <= maxLevel) {
            currentLevel += amount;
        } else if (currentLevel + amount > maxLevel) {
            currentLevel = maxLevel;
        }
    }

    void Shooter::SetLevel(const int amount) {
        currentLevel = amount;
    }

    Shooter::Shooter(Actor *owner) {
        this->owner = owner;
    }

    void Shooter::Shoot() {
        if (CanShoot() && !IsOnCooldown()) {
            ShootImpl();
        }
    }
}
