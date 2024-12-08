#include "vfx/Particle.h"

#include "framework/MathUtility.h"

namespace SpaceShooter {
    Particle::Particle(World *world, const std::string &texturePath): Actor(world, texturePath) {

    }

    void Particle::Update(const float deltaTime) {
        Actor::Update(deltaTime);
        Move(deltaTime);
        FadeOut();

        if (currentLifeTime >= lifeTime) Destroy();
        currentLifeTime += deltaTime;
    }

    void Particle::RandomVelocity(const float minSpeed, const float maxSpeed) {
        const auto speed = RandomRange(minSpeed, maxSpeed);
        velocity = RandomUnitVector();
        velocity.x *= speed;
        velocity.y *= speed;
    }

    void Particle::RandomSize(const float minSize, const float maxSize) {
        SetScale(RandomRange(minSize, maxSize));
    }

    void Particle::RandomLifetime(const float minLifetime, const float maxLifetime) {
        lifeTime = RandomRange(minLifetime, maxLifetime);
    }

    void Particle::Move(const float deltaTime) {
        SetPositionOffset(Vector2(velocity.x * deltaTime, velocity.y * deltaTime));

    }

    void Particle::FadeOut() {
        color = LerpColor(color, {255,255,255,0}, currentLifeTime / lifeTime);
        SetScale(1 - currentLifeTime / lifeTime);
    }
}
