#include "levels/MainMenu.h"


namespace SpaceShooter {
    MainMenu::MainMenu(Application *application)
        : World{application} {

    }

    void MainMenu::Initialize() {
        menuHUD = SpawnHUD<MainMenuHUD>();
    }
}
