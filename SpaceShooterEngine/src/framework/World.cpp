#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Actor.h"


namespace SpaceShooter {
    World::World(Application *application)
        : application(application),
          initialized(false) {
    }

    void World::InternalInitialize() {
        if (!initialized) {
            initialized = true;
            Initialize();
            LOG("Initializing world\n");
        }
    }

    void World::InternalUpdate(const float deltaTime) {
        for (const auto &actor : pendingActors) {
            childActors.push_back(actor);
            actor->InitializeInternal();
        }
        pendingActors.clear();
        for (const auto &actor : childActors) {
            actor->UpdateInternal(deltaTime);
        }

        Update(deltaTime);
        LOG("Updating world\n");
    }
}
