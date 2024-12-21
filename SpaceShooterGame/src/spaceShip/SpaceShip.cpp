#include "spaceShip/SpaceShip.h"

#include "framework/MathUtility.h"
#include "vfx/Explosion.h"
#include "weapon/Bullet.h"


namespace SpaceShooter {
    SpaceShip::SpaceShip(World *world, const std::string &texturePath, const CollisionLayers selfCollisionLayers, const CollisionLayers contactCollisionLayers): Actor(world, texturePath, selfCollisionLayers, contactCollisionLayers) {
    }

    void SpaceShip::Update(const float deltaTime) {
        Actor::Update(deltaTime);
        SetPositionOffset(Vector2{velocity.x * deltaTime, velocity.y * deltaTime});
        UpdateBlink(deltaTime);
    }

    void SpaceShip::Initialize() {
        Actor::Initialize();

        SetPhysicsEnabled(true);
        healthComponent.DamageTaken.BindAction(GetWeakRef(), &SpaceShip::OnDamageTaken);
        healthComponent.Death.BindAction(GetWeakRef(), &SpaceShip::OnDeath);
    }

    void SpaceShip::SetVelocity(const Vector2 &velocity) {
        this->velocity = velocity;
    }

    void SpaceShip::Blink() {
        if (blinkTime == 0) {
            blinkTime = blinkDuration;
        }
    }

    void SpaceShip::UpdateBlink(const float deltaTime) {
        if (blinkTime > 0) {
            blinkTime -= deltaTime;
            blinkTime = blinkTime > 0 ? blinkTime : 0;
            color = LerpColor(WHITE, blinkColorOffset, blinkTime/blinkDuration);
        }
    }

    void SpaceShip::ApplyDamage(const float amount) {
        healthComponent.ChangeHealth(amount);
    }

    void SpaceShip::OnContactBegin(Actor *actor) {
        Actor::OnContactBegin(actor);
        if (const auto *bullet = dynamic_cast<Bullet*>(actor)) {
            ApplyDamage(bullet->GetDamage());
        }
    }

    void SpaceShip::OnDamageTaken(const float amount, const float health, const float maxHealth) {
        Blink();
    }

    void SpaceShip::OnDeath() {
        const auto exp = new Explosion();
        exp->Spawn(GetWorld(), Position());
        Destroy();
        delete exp;
    }
}
