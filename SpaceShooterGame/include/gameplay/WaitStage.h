#pragma once
#include "gameplay/GameStage.h"


namespace SpaceShooter {
    class WaitStage final : public GameStage {
        public:
        explicit WaitStage(World* world, float waitDuration = 5.0f);

        void Initialize() override;

    private:
        float waitDuration;
    };
}