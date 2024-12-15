#include "enemy/EnemySpaceShip.h"

#include "framework/MathUtility.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    EnemySpaceShip::EnemySpaceShip(
        World *world,
        const std::string &texturePath,
        const float collisionDamage,
        const List<RewardFactoryFunction> &rewards)
    : SpaceShip{world, texturePath, CollisionLayers::Enemy, CollisionLayers::Player | CollisionLayers::PlayerBullet},
    collisionDamage{collisionDamage}, rewardFactories{rewards} {}

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

    void EnemySpaceShip::OnDeath() {
        SpaceShip::OnDeath();

        if (rewardFactories.empty()) return;
        const auto rewardIndex = RandomIntRange(0, static_cast<int>(rewardFactories.size() - 1));
        const auto reward = rewardFactories[rewardIndex](GetWorld());
        reward.lock()->SetPosition(GetTransform().position);
    }
}
