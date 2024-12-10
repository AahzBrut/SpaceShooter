#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/VanguardStage.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application) {
        const auto playerShip = SpawnActor<PlayerSpaceShip>();
        playerShip.lock()->SetPosition(Vector2{200, 600});
    }

    void GameLevelOne::InitStages() {
        AddStage(std::make_shared<VanguardStage>(this));
    }

    void GameLevelOne::Initialize() {
    }
}
