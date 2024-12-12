#pragma once
#include <raylib.h>

#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"

namespace SpaceShooter {
    class  World;

    class TweenBladeStage final : public GameStage {
    public:
        explicit TweenBladeStage(World* world);

        void StartStage() override;
        void SpawnTweenBlade();

    private:
        void OnStageFinished() override;

        float spawnInterval{1.5f};
        float spawnDistanceFromCenter{100};

        Vector2 leftSpawnPosition{0,0};
        Vector2 rightSpawnPosition{0,0};
        Vector2 spawnPosition{0,0};

        int spawnAmount{10};
        int spawnCount{0};

        TimerHandler spawnTimerHandler{};
    };
}
