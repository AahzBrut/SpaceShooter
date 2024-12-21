#pragma once
#include "framework/TimerManager.h"
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
        void SetShooter(Unique<Shooter> &&shooter);
        void ApplyDamage(float amount) override;
        void Initialize() override;

    private:
        float speed = 200.f;
        Vector2 moveInput{};
        Unique<Shooter> bulletShooter;
        float invulnerabilityTime{3};
        TimerHandle invulnerabilityTimer;
        bool invulnerable{true};
        float invulnerableFlashPeriod{0.5f};
        float invulnerabilityFlashTimer{invulnerableFlashPeriod};
        float invulnerableFlashDir{-1};

        void HandleInput();
        void ConsumeInput(float deltaTime);
        void UndoInvulnerability();
        void UpdateInvulnerabilityFlash(float deltaTime);
    };
}
