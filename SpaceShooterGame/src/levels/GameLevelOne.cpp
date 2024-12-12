#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/HexagonStage.h"
#include "enemy/TweenBladeStage.h"
#include "enemy/VanguardStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application) {
        SpawnActor<PlayerSpaceShip>().lock()->SetPosition(Vector2{200, 600});

//        SpawnActor<UFO>().lock()->SetPosition(Vector2{300, 200});
    }

    void GameLevelOne::InitStages() {
        AddStage(std::make_shared<VanguardStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<TweenBladeStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<HexagonStage>(this));
    }

    void GameLevelOne::Initialize() {
    }
}
