#include "framework/Core.h"
#include "framework/World.h"

#include <format>

#include "framework/Actor.h"


namespace SpaceShooter {
    World::World(Application *application)
        : application(application),
          initialized(false) {}

    World::~World() {
        for (auto iterator = pendingActors.begin(); iterator < pendingActors.end();) {
            iterator = pendingActors.erase(iterator);
        }
        for (auto iterator = childActors.begin(); iterator < childActors.end();) {
            iterator = childActors.erase(iterator);
        }
    }

    void World::InternalInitialize() {
        if (!initialized) {
            initialized = true;
            Initialize();
            LOG("Initializing world\n");
        }
    }

    void World::InternalUpdate(const float deltaTime) {
        for (const auto &actor: pendingActors) {
            childActors.push_back(actor);
            actor->InitializeInternal();
        }
        pendingActors.clear();

        for (auto iterator = childActors.begin(); iterator < childActors.end();) {
            if (const auto actor = iterator->get(); actor->IsPendingDestruction()) {
                iterator = childActors.erase(iterator);
            } else {
                actor->UpdateInternal(deltaTime);
                ++iterator;
            }
        }

        Update(deltaTime);
    }

    void World::Render() const {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        for (const auto &actor: childActors) {
            actor->Render();
        }

        const auto fpsString = std::format("FPS: {}", GetFPS());
        DrawText(fpsString.c_str(), 10, 10, 32, WHITE);

        EndDrawing();
    }
}
