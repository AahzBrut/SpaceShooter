#pragma once
#include "gameplay/GameStage.h"


namespace SpaceShooter {
    class Actor;
}

namespace SpaceShooter {
    class BossStage final : public GameStage {
        public:
        explicit BossStage(World* world);
        void StartStage() override;
    private:
        void OnBossDestroyed(Actor * bossActor);
    };
}
