#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/HexagonStage.h"
#include "enemy/TweenBladeStage.h"
#include "enemy/UFOStage.h"
#include "enemy/VanguardStage.h"
#include "gameplay/WaitStage.h"
#include "player/Player.h"
#include "player/PlayerManager.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application) {}

    void GameLevelOne::InitStages() {
        AddStage(std::make_shared<VanguardStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<TweenBladeStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<HexagonStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<UFOStage>(this));
    }

    void GameLevelOne::Initialize() {
        auto newPlayer = PlayerManager::Get().CreateNewPlayer();
        newPlayer.SpawnSpaceship(this);
    }
}
