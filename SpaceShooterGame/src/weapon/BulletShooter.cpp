#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    BulletShooter::BulletShooter(Actor *owner, const float coolDownTimeout) : Shooter(owner) {
        this->coolDownTimeout = coolDownTimeout;
    }

    bool BulletShooter::IsOnCooldown() {
        return lastShootTime + this->coolDownTimeout > GetTime();
    }

    void BulletShooter::ShootImpl() {
        lastShootTime = GetTime();
        LOG("Shot fired.");
    }
}
