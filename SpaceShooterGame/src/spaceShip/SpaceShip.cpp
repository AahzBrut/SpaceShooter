#include "spaceShip/SpaceShip.h"

#include "weapon/Bullet.h"


namespace SpaceShooter {
    SpaceShip::SpaceShip(World *world, const std::string &texturePath, const CollisionLayers selfCollisionLayers, const CollisionLayers contactCollisionLayers): Actor(world, texturePath, selfCollisionLayers, contactCollisionLayers) {
    }

    void SpaceShip::Update(const float deltaTime) {
        Actor::Update(deltaTime);
        SetPositionOffset(Vector2{velocity.x * deltaTime, velocity.y * deltaTime});
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

    void SpaceShip::OnContactBegin(Actor *actor) {
        Actor::OnContactBegin(actor);
        if (actor == dynamic_cast<Bullet*>(actor)) {
            const auto bullet = dynamic_cast<Bullet*>(actor);
            healthComponent.ChangeHealth(bullet->GetDamage());
        }
    }

    void SpaceShip::Shoot() {}

    void SpaceShip::OnDamageTaken(const float amount, const float health, const float maxHealth) {
        LOG("Damage taken %f, current health: %f/%f", amount, health, maxHealth);
    }

    void SpaceShip::OnDeath() {
        LOG("Spaceship destroyed");
        Destroy();
    }
}
