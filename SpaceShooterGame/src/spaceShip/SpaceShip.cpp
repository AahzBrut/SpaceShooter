#include "spaceShip/SpaceShip.h"


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
    }

    void SpaceShip::SetVelocity(const Vector2 &velocity) {
        this->velocity = velocity;
    }

    void SpaceShip::Shoot() {}
}
