#pragma once
#include "framework/TimerManager.h"
#include "framework/World.h"


namespace SpaceShooter {
    class PlayerSpaceShip;

    class GameLevelOne final : public World {
    public:
        explicit GameLevelOne(Application *application);

    private:
        TimerHandler timerIndex{};
        Weak<PlayerSpaceShip> playerSpaceShip;

        void InitStages() override;
        void Initialize() override;
        void OnPlayerShipDestroyed(Actor* actor);
        void GameOver();
    };
}
