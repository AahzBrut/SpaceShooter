#pragma once
#include <raylib.h>

#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"


namespace SpaceShooter {
    class ChaosStage final : public GameStage {
    public:
        explicit ChaosStage(World *world);

        void StartStage() override;

    private:
        float spawnInterval{4};
        float minSpawnInterval{.8f};
        float spawnIntervalDecrement{.5f};
        float spawnIntervalDecrementInterval{5};
        float stageDuration{60};

        TimerHandle difficultyTimer;
        TimerHandle spawnTimer;

        void OnStageFinished() override;
        void SpawnVanguard();
        void SpawnTweenBlade();
        void SpawnHexagon();
        void SpawnUFO();

        void IncreaseDifficulty();
        void StageDurationReached();

        Vector2 GetRandomSpawnPositionTop() const;
        Vector2 GetRandomSpawnPositionSide() const;
    };
}
