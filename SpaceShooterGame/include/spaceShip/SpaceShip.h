#pragma once
#include "framework/Actor.h"


namespace SpaceShooter {
    class SpaceShip : public Actor {
    public:
        explicit SpaceShip(World* world, const std::string& texturePath = "");
        void Update(float deltaTime) override;
        void SetVelocity(const Vector2& velocity);
        [[nodiscard]] Vector2 GetVelocity() const { return velocity; }

        virtual void Shoot();
    private:
        Vector2 velocity{};
    };
}
