#pragma once

#include <framework/Application.h>

#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    class GameApplication final : public Application {
    public:
        GameApplication();
        void Update(float deltaTime) override;
    private:
        float counter;
        Weak<PlayerSpaceShip> playerShip;
    };
}
