#include "enemy/EnemySpaceShip.h"

#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    EnemySpaceShip::EnemySpaceShip(World *world, const std::string &texturePath, const float collisionDamage)
    : SpaceShip{world, texturePath, CollisionLayers::Enemy, CollisionLayers::Player | CollisionLayers::PlayerBullet},
    collisionDamage{collisionDamage} {}

    void EnemySpaceShip::Update(const float deltaTime) {
        SpaceShip::Update(deltaTime);

        if (IsOutOfWindowBounds(GetSize().x * 3)) Destroy();
    }

    void EnemySpaceShip::OnContactBegin(Actor *actor) {
        SpaceShip::OnContactBegin(actor);
        if (auto *player = dynamic_cast<PlayerSpaceShip*>(actor)) {
            player->ApplyDamage(collisionDamage);
        }
    }
}
