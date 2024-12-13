#pragma once
#include "spaceShip/SpaceShip.h"
#include "weapon/Shooter.h"


namespace SpaceShooter {
    class PlayerSpaceShip final : public SpaceShip {
    public:
        explicit PlayerSpaceShip(World *world,
                                 const std::string &texturePath = "assets/SpaceShooterRedux/PNG/playerShip1_blue.png");

        void Update(float deltaTime) override;
        void ClampInputOnEdge();
        void Shoot() override;
        void SetShooter(Unique<Shooter>&& shooter);

    private:
        float speed = 200.f;
        Vector2 moveInput{};
        Unique<Shooter> bulletShooter;

        void HandleInput();
        void ConsumeInput(float deltaTime);
    };
}
