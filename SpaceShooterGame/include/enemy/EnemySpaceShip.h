#pragma once
#include "player/Reward.h"
#include "spaceShip/SpaceShip.h"

namespace SpaceShooter {
    class EnemySpaceShip : public SpaceShip {
    public:
        EnemySpaceShip(World *world, const std::string &texturePath, float collisionDamage = 200.f,
            const List<RewardFactoryFunction>& rewards = {
            CreateHealthReward,
            CreateThreeWayReward,
            CreateFrontalWiperReward
        });

        void Update(float deltaTime) override;
        void OnContactBegin(Actor *actor) override;

    private:
        float collisionDamage;
        List<RewardFactoryFunction> rewardFactories;

        void OnDeath() override;
    };
}
