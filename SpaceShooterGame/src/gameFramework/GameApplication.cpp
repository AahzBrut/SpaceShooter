#include "framework/Application.h"
#include "framework/World.h"
#include "gameFramework/GameApplication.h"


SpaceShooter::Application *GetApplication() {
    return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication() {
        const auto world = LoadWorld<World>();
        world.lock()->SpawnActor<Actor>();
        actorToDestroy = world.lock()->SpawnActor<Actor>();
        counter = 0;
    }

    void GameApplication::Update(float deltaTime) {
        counter += deltaTime;

        if (counter >= 1.0f) {
            if (!actorToDestroy.expired()) {
                actorToDestroy.lock()->Destroy();
            }
        }
    }
}
