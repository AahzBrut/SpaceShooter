#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Shooter {
    public:
        virtual ~Shooter() = default;

        void Shoot();
        Actor *GetOwner() const;

        virtual bool CanShoot() { return true; }
        virtual bool IsOnCooldown() { return false; }

    protected:
        explicit Shooter(Actor *owner);

    private:
        Actor *owner{};
        virtual void ShootImpl() = 0;
    };
}
