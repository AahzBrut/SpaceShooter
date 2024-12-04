#include "spaceShip/SpaceShip.h"



namespace SpaceShooter {
    SpaceShip::SpaceShip(World *world, const std::string &texturePath): Actor(world, texturePath) {

    }

    void SpaceShip::Update(const float deltaTime) {
        Actor::Update(deltaTime);

        SetPositionOffset(Vector2{velocity.x * deltaTime, velocity.y * deltaTime});
    }

    void SpaceShip::SetVelocity(const Vector2 &velocity) {
        this->velocity = velocity;
    }
}
