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
        actor.lock()->SetTexture("assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
        const auto [x, y] = actor.lock()->GetTextureSize();
        actor.lock()->SetPosition(Vector2{100, 100});
        actor.lock()->SetRotation(0);
        actor.lock()->SetPivotOffset(Vector2{x / 2, y / 2});
        actor.lock()->SetScale(1.5f);
        actorToDestroy = world.lock()->SpawnActor<Actor>();
        actorToDestroy.lock()->SetTexture("assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
        actorToDestroy.lock()->SetPosition(Vector2{200, 200});
        actorToDestroy.lock()->SetPivotOffset(Vector2{x / 2, y / 2});
        actorToDestroy.lock()->SetScale(2.5f);
        counter = 0;
    }

    void GameApplication::Update(const float deltaTime) {
        counter += deltaTime;

        if (counter >= 3.0f) {
            if (!actorToDestroy.expired()) {
                actorToDestroy.lock()->Destroy();
            }
        }
    }
}
