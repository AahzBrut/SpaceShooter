#include "weapon/BulletShooter.h"

#include "audio/AudioManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"
#include "weapon/Bullet.h"

namespace SpaceShooter {
    BulletShooter::BulletShooter(Actor *owner,
                                 const float coolDownTimeout,
                                 const CollisionLayers bulletLayer,
                                 const CollisionLayers bulletMaskLayer)
        : Shooter(owner),
          bulletLayer{bulletLayer},
          bulletMaskLayer{bulletMaskLayer} {
        this->coolDownTimeout = coolDownTimeout;
    }

    bool BulletShooter::IsOnCooldown() {
        return lastShootTime + coolDownTimeout / static_cast<float>(GetCurrentLevel() + 1) > GetTime();
    }

    void BulletShooter::ShootImpl() {
        if (shotSound) AudioManager::Get().PlaySoundEffect(*shotSound);
        lastShootTime = static_cast<float>(GetTime());
        const Weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(
            GetOwner(), bulletLayer, bulletMaskLayer);
        if (!bulletTexturePath.empty()) newBullet.lock()->SetTexture(bulletTexturePath);
        newBullet.lock()->SetPosition(GetOwner()->Position() + muzzleOffset);
        newBullet.lock()->SetRotation(GetOwner()->Rotation() + muzzleRotation);
    }
}
