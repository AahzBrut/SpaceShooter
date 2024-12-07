#include "weapon/Bullet.h"

namespace SpaceShooter {
    Bullet::Bullet(World *world, Actor *owner, const CollisionLayers bulletLayer, const CollisionLayers bulletMaskLayer, const std::string &texturePath, const float speed, const float damage)
        : Actor(world, texturePath, bulletLayer, bulletMaskLayer),
          owner{owner},
          speed{speed},
          damage{damage} {
        CenterPivotOffset();
    }

    void Bullet::Initialize() {
        Actor::Initialize();

        SetPhysicsEnabled(true);
    }

    void Bullet::Update(const float deltaTime) {
        Actor::Update(deltaTime);
        Move(deltaTime);
        if (IsOutOfWindowBounds()) Destroy();
    }

    void Bullet::Move(const float deltaTime) {
        const auto [directionX, directionY] = GetForwardVector();
        SetPositionOffset(Vector2{directionX * speed * deltaTime, directionY * speed * deltaTime});
    }
}
