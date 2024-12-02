#include "framework/Application.h"
#include "framework/World.h"
#include "gameFramework/GameApplication.h"


SpaceShooter::Application *GetApplication() {
    return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication(): Application{600, 900, "Space Shooter"} {
        const auto world = LoadWorld<World>();
        const auto actor = world.lock()->SpawnActor<Actor>();
        actor.lock()->SetTexture("assets/SpaceShooterRedux/sample.png");
        actorToDestroy = world.lock()->SpawnActor<Actor>();
        actorToDestroy.lock()->SetTexture("assets/SpaceShooterRedux/sample.png");
        counter = 0;
    }

    void GameApplication::Update(const float deltaTime) {
        counter += deltaTime;

        if (counter >= 1.0f) {
            if (!actorToDestroy.expired()) {
                actorToDestroy.lock()->Destroy();
            }
        }
    }
}
