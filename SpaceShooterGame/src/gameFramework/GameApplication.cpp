#include "gameFramework/GameApplication.h"

#include "framework/Application.h"
#include "levels/GameLevelOne.h"
#include "levels/MainMenu.h"


SpaceShooter::Application *GetApplication() {
    return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication(): Application{600, 900, "Space Shooter"} {
//        const auto world = LoadWorld<GameLevelOne>();
        const auto world = LoadWorld<MainMenu>();
    }
}
