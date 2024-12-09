#pragma once
#include "framework/World.h"


namespace SpaceShooter {
    class GameLevelOne : public World {
        public:
        explicit GameLevelOne(Application *application);

    private:
        unsigned int timerIndex{0};

        void Initialize() override;
        void OnTimerTimeout();
    };
}
