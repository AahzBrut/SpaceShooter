#include "levels/MainMenu.h"

#include "EntryPoint.h"
#include "framework/Application.h"
#include "levels/GameLevelOne.h"
#include "widgets/MainMenuHUD.h"

namespace SpaceShooter {
    MainMenu::MainMenu(Application *application)
        : World{application} {}

    void MainMenu::Initialize() {
        menuHUD = SpawnHUD<MainMenuHUD>();
        menuHUD.lock()->StartButtonPressed.BindAction(GetWeakRef(), &MainMenu::StartGame);
        menuHUD.lock()->QuitButtonPressed.BindAction(GetWeakRef(), &MainMenu::QuitGame);
    }

    void MainMenu::StartGame() {
        GetApplication()->LoadWorld<GameLevelOne>();
    }

    void MainMenu::QuitGame() {
        GetApplication()->Quit();
    }
}
