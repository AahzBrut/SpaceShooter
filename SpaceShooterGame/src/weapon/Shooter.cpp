#include "weapon/Shooter.h"

namespace SpaceShooter {
    Shooter::Shooter(Actor *owner) {
        this->owner = owner;
    }

    void Shooter::Shoot() {
        if (CanShoot() && !IsOnCooldown()) {
            ShootImpl();
        }
    }

    Actor * Shooter::GetOwner() const {
        return owner;
    }
}
