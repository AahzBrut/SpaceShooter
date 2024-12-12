#pragma once
#include <raylib.h>

#include "framework/TimerManager.h"
#include "framework/World.h"
#include "gameplay/GameStage.h"


namespace SpaceShooter {
    class HexagonStage final : public GameStage {
    public:
        explicit HexagonStage(World *world);

        void StartStage() override;

    private:
        float spawnInterval{5};
        float spawnSideOffset{80};

        int waveAmount{5};
        int waveCount{0};

        Vector2 midSpawnPosition{GetWorld()->GetWindowSize().x * 0.5f, -100};
        Vector2 leftSpawnPosition{GetWorld()->GetWindowSize().x * 0.5f - spawnSideOffset, -100.f - spawnSideOffset};
        Vector2 rightSpawnPosition{GetWorld()->GetWindowSize().x * 0.5f + spawnSideOffset, -100.f - spawnSideOffset};

        TimerHandler spawnTimer{};

        void OnStageFinished() override;
        void SpawnHexagon();
    };
}
