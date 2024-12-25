#include "levels/GameLevelOne.h"

#include <memory>

#include "enemy/BossStage.h"
#include "enemy/ChaosStage.h"
#include "enemy/HexagonStage.h"
#include "enemy/TweenBladeStage.h"
#include "enemy/UFOStage.h"
#include "enemy/VanguardStage.h"
#include "framework/Application.h"
#include "framework/BackgroundLayer.h"
#include "framework/ScrollingBackground.h"
#include "gameplay/WaitStage.h"
#include "levels/MainMenu.h"
#include "player/Player.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceShip.h"
#include "widgets/GameHUD.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application) {}

    void GameLevelOne::OnQuitButtonPressed() {
        GetApplication()->Quit();
    }

    void GameLevelOne::OnRestartButtonPressed() {
        PlayerManager::Get().DeletePlayer();
        GetApplication()->LoadWorld<MainMenu>();
    }

    void GameLevelOne::InitStages() {
        AddStage(std::make_shared<BossStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<VanguardStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<TweenBladeStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<HexagonStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 15));
        AddStage(std::make_shared<UFOStage>(this));
        AddStage(std::make_shared<WaitStage>(this, 5));
        AddStage(std::make_shared<ChaosStage>(this));
    }

    void GameLevelOne::Initialize() {
        SpawnActor<ScrollingBackground>();
        SpawnActor<BackgroundLayer>(List<std::string>{
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_med3.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_small1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_small2.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny2.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_med1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_med2.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_small1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_small2.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny1.png",
            "assets/SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny2.png"
        });

        auto &newPlayer = PlayerManager::Get().CreateNewPlayer();
        playerSpaceShip = newPlayer.SpawnSpaceship(this);
        playerSpaceShip.lock()->Destroyed.BindAction(GetWeakRef(), &GameLevelOne::OnPlayerShipDestroyed);

        gameHUD = SpawnHUD<GameHUD>();
        gameHUD.lock()->RestartButtonPressed.BindAction(GetWeakRef(), &GameLevelOne::OnRestartButtonPressed);
        gameHUD.lock()->QuitButtonPressed.BindAction(GetWeakRef(), &GameLevelOne::OnQuitButtonPressed);
    }

    void GameLevelOne::AllStagesFinished() {
        gameHUD.lock()->GameFinished(true);
    }

    void GameLevelOne::OnPlayerShipDestroyed([[maybe_unused]] Actor *actor) {
        playerSpaceShip = PlayerManager::Get().GetPlayer()->SpawnSpaceship(this);
        if (!playerSpaceShip.expired()) {
            playerSpaceShip.lock()->Destroyed.BindAction(GetWeakRef(), &GameLevelOne::OnPlayerShipDestroyed);
        } else {
            GameOver();
        }
    }

    void GameLevelOne::GameOver() const {
        gameHUD.lock()->GameFinished(false);
    }
}
