#include "gameFramework/GameApplication.h"

SpaceShooter::Application* GetApplication() {
    return new SpaceShooter::GameApplication();
}
