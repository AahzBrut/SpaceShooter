#pragma once
#include <raylib.h>

#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"


namespace SpaceShooter {
    class VanguardStage : public GameStage {
    public:
        explicit VanguardStage(World *world);
        void Initialize() override;

    private:
        float spawnInterval;
        float waveInterval;
        float spawnOffsetX;

        Vector2 leftSpawnPosition;
        Vector2 rightSpawnPosition;
        Vector2 spawnPosition;

        TimerHandler spawnTimerHandler;
        TimerHandler waveTimerHandler;

        int wavesToSpawn;
        int waveCounter;

        int vanguardsPerWave;
        int vanguardCounter;

        void OnStageFinished() override;
        void SpawnVanguard();
        void SwitchWave();
    };
}
