#include "vfx/Explosion.h"

#include "framework/World.h"
#include "framework/MathUtility.h"
#include "vfx/Particle.h"

namespace SpaceShooter {
    Explosion::Explosion(
        const int particleAmount,
        const float lifeTimeMin,
        const float lifeTimeMax,
        const float sizeMin,
        const float sizeMax,
        const float speedMin,
        const float speedMax,
        const Color &color,
        const List<std::string> &particleImagePaths)
        : particleAmount(particleAmount),
          lifeTimeMin(lifeTimeMin),
          lifeTimeMax(lifeTimeMax),
          sizeMin(sizeMin),
          sizeMax(sizeMax),
          speedMin(speedMin),
          speedMax(speedMax),
          color{color},
          particleImagePaths{particleImagePaths} {}

    void Explosion::Spawn(World *world, const Vector2 &position) const {
        if (!world) return;
        for (int i = 0; i < particleAmount; i++) {
            const auto particleImagePath = particleImagePaths[static_cast<int>(RandomRange(
                0, static_cast<float>(particleImagePaths.size())))];
            Weak<Particle> particle = world->SpawnActor<Particle>(particleImagePath);
            particle.lock()->SetPosition(position);
            particle.lock()->RandomLifetime(lifeTimeMin, lifeTimeMax);
            particle.lock()->RandomSize(sizeMin, sizeMax);
            particle.lock()->RandomVelocity(speedMin, speedMax);
            particle.lock()->SetColor(color);
        }
    }
}
