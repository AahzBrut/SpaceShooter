#pragma once
#include "spaceShip/SpaceShip.h"


namespace SpaceShooter {
    class PlayerSpaceShip : public SpaceShip {
    public:
        explicit PlayerSpaceShip(World *world,
                                 const std::string &texturePath = "assets/SpaceShooterRedux/PNG/playerShip1_blue.png");

        void Update(float deltaTime) override;

    private:
        float speed = 200.f;
        Vector2 moveInput{};

        void HandleInput();
        void ConsumeInput(float deltaTime);
    };
}
