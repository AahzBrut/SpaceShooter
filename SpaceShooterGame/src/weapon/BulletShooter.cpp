#include "weapon/BulletShooter.h"

#include "framework/World.h"
#include "weapon/Bullet.h"

namespace SpaceShooter {
    BulletShooter::BulletShooter(Actor *owner, const float coolDownTimeout) : Shooter(owner) {
        this->coolDownTimeout = coolDownTimeout;
    }

    bool BulletShooter::IsOnCooldown() {
        return lastShootTime + this->coolDownTimeout > GetTime();
    }

    void BulletShooter::ShootImpl() {
        lastShootTime = static_cast<float>(GetTime());
        const Weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner());
        newBullet.lock()->SetPosition(GetOwner()->Position());
        newBullet.lock()->SetRotation(GetOwner()->Rotation());
    }
}
