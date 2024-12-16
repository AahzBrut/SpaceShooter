#include "player/Reward.h"

#include <utility>

#include "framework/MathUtility.h"
#include "player/PlayerSpaceShip.h"
#include "weapon/FrontalWiper.h"
#include "weapon/ThreeWayShooter.h"

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


        SetPositionOffset(speed * deltaTime * Vector2{0.f, 1.f});
    }

    void Reward::OnContactBegin(Actor *actor) {
        if (const auto player = dynamic_cast<PlayerSpaceShip *>(actor);
            player != nullptr && !player->IsPendingDestruction()) {
            rewardFunction(player);
            Destroy();
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
        player->GetHealthComponent().ChangeHealth(-10);
    }

    void RewardThreeWayShooter(PlayerSpaceShip *player) {
        player->SetShooter(std::make_unique<ThreeWayShooter>(player, .1f, Vector2{0.f, 0.f}));
    }

    void RewardFrontalWiper(PlayerSpaceShip *player) {
        player->SetShooter(std::make_unique<FrontalWiper>(player, .1f, Vector2{0.f, 0.f}));
    }
}
