#include "framework/Actor.h"
#include "framework/Core.h"

namespace SpaceShooter {
    Actor::Actor(World *world) : world(world) {
    }

    void Actor::InitializeInternal() {
        LOG("Initializing Actor");
        Initialize();
    }

    void Actor::UpdateInternal(const float deltaTime) {
        LOG("Updating Actor");
        Update(deltaTime);
    }
}
