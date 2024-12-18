#pragma once
#include "framework/Delegate.h"
#include "framework/Object.h"


namespace SpaceShooter {
    class PlayerSpaceShip;
    class World;

    class Player final : public Object {
    public:
        explicit Player() = default;

        Weak<PlayerSpaceShip> SpawnSpaceship(World *world);
        Weak<PlayerSpaceShip> GetSpaceship() const { return spaceShip; }

        void AddLifeCount(unsigned int count);
        unsigned int GetLifeCount() const { return lifeCount; }

        void AddScore(unsigned int score);
        unsigned int GetScore() const { return score; }

        Delegate<unsigned int> LifeCountChanged;
        Delegate<unsigned int> ScoreChanged;
        Delegate<> LifeCountDepleted;

    private:
        unsigned int lifeCount{4};
        unsigned int score{0};
        Weak<PlayerSpaceShip> spaceShip{};
    };
}
