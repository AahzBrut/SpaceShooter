#pragma once
#include <functional>

#include "framework/Actor.h"
#include "framework/World.h"


namespace SpaceShooter {
    class Reward;
    class PlayerSpaceShip;
    using RewardFunction = std::function<void(PlayerSpaceShip *)>;
    using RewardFactoryFunction = std::function<Weak<Reward>(World *)>;

    class Reward final : public Actor {
    public:
        explicit Reward(World *world, const std::string &texturePath,
                        RewardFunction rewardFunction, float speed = 200.f);

        void Initialize() override;
        void Update(float deltaTime) override;

    private:
        float speed;
        RewardFunction rewardFunction;

        void OnContactBegin(Actor *actor) override;
    };

    Weak<Reward> CreateHealthReward(World *world);
    Weak<Reward> CreateThreeWayReward(World *world);
    Weak<Reward> CreateFrontalWiperReward(World *world);
    Weak<Reward> CreateLifeReward(World *world);

    Weak<Reward> CreateReward(World *world, const std::string &texturePath, const RewardFunction &rewardFunction);

    void RewardHealth(PlayerSpaceShip *playerShip);
    void RewardThreeWayShooter(PlayerSpaceShip *playerShip);
    void RewardFrontalWiper(PlayerSpaceShip *playerShip);
    void RewardLife(PlayerSpaceShip *playerShip);
}
