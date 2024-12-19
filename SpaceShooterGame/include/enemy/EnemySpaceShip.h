#pragma once
#include "player/Reward.h"
#include "spaceShip/SpaceShip.h"

namespace SpaceShooter {
    class EnemySpaceShip : public SpaceShip {
    public:
        EnemySpaceShip(World *world, const std::string &texturePath, float collisionDamage = 200.f,
                       const List<RewardFactoryFunction> &rewards = {
                           CreateHealthReward,
                           CreateThreeWayReward,
                           CreateFrontalWiperReward
                       });

        void Update(float deltaTime) override;
        void OnContactBegin(Actor *actor) override;
        void SpawnReward() const;
        void SetRewardAmount(const unsigned int amount) { reward = amount; }

    private:
        float collisionDamage;
        unsigned int reward{10};
        List<RewardFactoryFunction> rewardFactories;

        void OnDeath() override;
    };
}
