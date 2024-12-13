#include "player/Reward.h"

#include <utility>

#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    Reward::Reward(
        World *world,
        const std::string &texturePath,
        RewardFunction rewardFunction,
        const float speed)
        : Actor(world, texturePath, CollisionLayers::Reward, CollisionLayers::Player),
          speed{speed},
          rewardFunction{std::move(rewardFunction)} {}

    void Reward::Initialize() {
        SetPhysicsEnabled(true);
    }

    void Reward::Update(const float deltaTime) {
        Actor::Update(deltaTime);
    }

    void Reward::OnContactBegin(Actor *actor) {
        if (const auto player = dynamic_cast<PlayerSpaceShip *>(actor);
            player != nullptr && !player->IsPendingDestruction()) {
            rewardFunction(player);
        }
    }

    Weak<Reward> CreateHealthReward(World *world) {
        return CreateReward(world, "assets/SpaceShooterRedux/PNG/Pickups/playerLife1_blue.png",
                            RewardHealth);
    }

    Weak<Reward> CreateThreeWayReward(World *world) {
        return CreateReward(world, "assets/SpaceShooterRedux/PNG/Pickups/three_shooter_pickup.png",
                            RewardThreeWayShooter);
    }

    Weak<Reward> CreateFrontalWiperReward(World *world) {
        return CreateReward(world, "assets/SpaceShooterRedux/PNG/Pickups/front_row_shooter_pickup.png",
                            RewardFrontalWiper);
    }

    Weak<Reward> CreateReward(World *world, const std::string &texturePath, const RewardFunction &rewardFunction) {
        return world->SpawnActor<Reward>(texturePath, rewardFunction);
    }

    void RewardHealth(PlayerSpaceShip *player) {
        LOG("RewardHealth");
        player->GetHealthComponent().ChangeHealth(-10);
    }

    void RewardThreeWayShooter(PlayerSpaceShip *player) {
        LOG("Reward three way shooter");
    }

    void RewardFrontalWiper(PlayerSpaceShip *player) {
        LOG("Reward frontal wiper");
    }
}
