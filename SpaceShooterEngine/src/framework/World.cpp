#include "framework/Core.h"
#include "framework/World.h"


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

    void World::InternalUpdate(float deltaTime) {
        Update(deltaTime);
        LOG("Updating world\n");
    }
}
