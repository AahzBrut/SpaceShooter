#pragma once
#include "spaceShip/SpaceShip.h"
#include "weapon/BulletShooter.h"


namespace SpaceShooter {
    class PlayerSpaceShip : public SpaceShip {
    public:
        explicit PlayerSpaceShip(World *world,
                                 const std::string &texturePath = "assets/SpaceShooterRedux/PNG/playerShip1_blue.png");

        void Update(float deltaTime) override;
        void ClampInputOnEdge();
        void Shoot() override;

    private:
        float speed = 200.f;
        Vector2 moveInput{};
        Unique<BulletShooter> bulletShooter;

        void HandleInput();
        void ConsumeInput(float deltaTime);
    };
}
