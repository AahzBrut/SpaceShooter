#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Particle : public Actor {
    public:
        Particle(World *world, const std::string &texturePath);

        void Update(float deltaTime) override;

        void RandomVelocity(float minSpeed, float maxSpeed);
        void RandomSize(float minSize, float maxSize);
        void RandomLifetime(float minLifetime, float maxLifetime);

    private:
        Vector2 velocity{};
        float lifeTime{1.0f};
        float currentLifeTime{};

        void Move(float deltaTime);
        void FadeOut();
    };
}
