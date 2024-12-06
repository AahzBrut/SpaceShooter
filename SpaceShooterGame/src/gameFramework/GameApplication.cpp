#include "framework/Application.h"
#include "framework/World.h"
#include "gameFramework/GameApplication.h"

#include "spaceShip/SpaceShip.h"


SpaceShooter::Application *GetApplication() {
    return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication(): Application{600, 900, "Space Shooter"} {
        const auto world = LoadWorld<World>();
        const auto actor = world.lock()->SpawnActor<SpaceShip>();
        actor.lock()->SetTexture("assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
        actor.lock()->SetPosition(Vector2{100, 100});
        actor.lock()->CenterPivotOffset();
        actor.lock()->SetRotation(-90);
        playerShip = world.lock()->SpawnActor<PlayerSpaceShip>();
        playerShip.lock()->SetPosition(Vector2{200, 600});
        playerShip.lock()->CenterPivotOffset();
        counter = 0;
    }

    void GameApplication::Update(const float deltaTime) {
        counter += deltaTime;

        // if (!playerShip.expired()) playerShip.lock()->SetRotation(counter * 90);
        //
        //  if (counter >= 3.0f) {
        //      if (!playerShip.expired()) {
        //          playerShip.lock()->Destroy();
        //      }
        //  }
    }
}
