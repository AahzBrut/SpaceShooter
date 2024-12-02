#include "framework/Application.h"
#include "framework/World.h"
#include "gameFramework/GameApplication.h"


SpaceShooter::Application* GetApplication() {
        return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication() {
        LoadWorld<World>();
    }
}