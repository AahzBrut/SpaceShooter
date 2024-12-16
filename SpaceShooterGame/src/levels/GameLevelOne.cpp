#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/HexagonStage.h"
#include "enemy/TweenBladeStage.h"
#include "enemy/UFOStage.h"
#include "enemy/VanguardStage.h"
#include "gameplay/WaitStage.h"
#include "player/Player.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceShip.h"

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
        playerSpaceShip = newPlayer.SpawnSpaceship(this);
        playerSpaceShip.lock()->Destroyed.BindAction(GetWeakRef(), &GameLevelOne::OnPlayerShipDestroyed);
    }

    void GameLevelOne::OnPlayerShipDestroyed([[maybe_unused]] Actor *actor) {
        playerSpaceShip = PlayerManager::Get().GetPlayer()->SpawnSpaceship(this);
        if (!playerSpaceShip.expired()) {
            playerSpaceShip.lock()->Destroyed.BindAction(GetWeakRef(), &GameLevelOne::OnPlayerShipDestroyed);
        } else {
            GameOver();
        }
    }

    void GameLevelOne::GameOver() {
        LOG("GAME OVER");
    }
}
