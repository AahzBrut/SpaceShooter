#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Bullet : public Actor {
    public:
        Bullet(World *world, Actor *owner, const std::string &texturePath = "assets/SpaceShooterRedux/PNG/Lasers/laserBlue01.png", float speed = 600.f, float damage = 10.f);

        void SetSpeed(const float speed) { this->speed = speed; }
        [[nodiscard]] float GetSpeed() const { return this->speed; }
        void SetDamage(const float damage) { this->damage = damage; }
        [[nodiscard]] float GetDamage() const { return this->damage; }

        void Update(float deltaTime) override;

    private:
        Actor *owner;
        float speed;
        float damage;

        void Move(float deltaTime);
    };
}
