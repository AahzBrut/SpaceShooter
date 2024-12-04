#pragma once
#include "spaceShip/SpaceShip.h"


namespace SpaceShooter {
    class PlayerSpaceShip : public SpaceShip {
    public:
        PlayerSpaceShip(World* world, const std::string& texturePath = "assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
    };
}
