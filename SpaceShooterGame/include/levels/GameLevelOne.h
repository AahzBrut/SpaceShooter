#pragma once
#include "framework/TimerManager.h"
#include "framework/World.h"


namespace SpaceShooter {
    class GameLevelOne : public World {
        public:
        explicit GameLevelOne(Application *application);

    private:
        TimerHandler timerIndex{};

        void InitStages() override;
        void Initialize() override;
        void OnTimerTimeout();
    };
}
