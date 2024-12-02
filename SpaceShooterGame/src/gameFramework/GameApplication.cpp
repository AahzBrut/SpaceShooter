#include "framework/Application.h"
#include "framework/World.h"
#include "gameFramework/GameApplication.h"


SpaceShooter::Application* GetApplication() {
        return new SpaceShooter::GameApplication();
}

namespace SpaceShooter {
    GameApplication::GameApplication() {
        auto world = LoadWorld<World>();
        world.lock()->SpawnActor<Actor>();
    }
}