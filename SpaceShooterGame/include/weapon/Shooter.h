#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Shooter {
    public:
        virtual ~Shooter() = default;

        void Shoot();
        [[nodiscard]] Actor *GetOwner() const { return owner; }

        virtual bool CanShoot() { return true; }
        virtual bool IsOnCooldown() { return false; }
        [[nodiscard]] int GetCurrentLevel() const { return currentLevel; }
        [[nodiscard]] int GetMaxLevel() const { return maxLevel; }
        virtual void IncreaseLevel(int amount);

    protected:
        explicit Shooter(Actor *owner);

    private:
        Actor *owner{};
        int currentLevel{0};
        int maxLevel{5};

        virtual void ShootImpl() = 0;
    };
}
