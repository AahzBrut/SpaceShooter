#pragma once
#include "framework/TimerManager.h"
#include "framework/World.h"


namespace SpaceShooter {
    class PlayerSpaceShip;
    class GameHUD;

    class GameLevelOne final : public World {
    public:
        explicit GameLevelOne(Application *application);

    private:
        TimerHandle timerIndex{};
        Weak<PlayerSpaceShip> playerSpaceShip;
        Weak<GameHUD> gameHUD;

        void OnQuitButtonPressed();
        void OnRestartButtonPressed();
        void InitStages() override;
        void Initialize() override;
        void AllStagesFinished() override;
        void OnPlayerShipDestroyed(Actor* actor);
        void GameOver() const;
    };
}
