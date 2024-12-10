#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/TweenBladeStage.h"
#include "enemy/VanguardStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application) {
        const auto playerShip = SpawnActor<PlayerSpaceShip>();
        playerShip.lock()->SetPosition(Vector2{200, 600});
    }

    void GameLevelOne::InitStages() {
        AddStage(std::make_shared<VanguardStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<TweenBladeStage>(this));
    }

    void GameLevelOne::Initialize() {
    }
}
