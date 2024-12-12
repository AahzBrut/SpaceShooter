#include "enemy/VanguardStage.h"

#include "enemy/Vanguard.h"
#include "framework/MathUtility.h"
#include "framework/Object.h"
#include "framework/World.h"

namespace SpaceShooter {
    VanguardStage::VanguardStage(World *world)
        : GameStage(world),
          spawnInterval{2.5f},
          waveInterval{1},
          spawnOffsetX{100},
          leftSpawnPosition{0, 0},
          rightSpawnPosition{0, 0},
          spawnPosition{0, 0},
          wavesToSpawn{4},
          waveCounter{0},
          vanguardsPerWave{5},
          vanguardCounter{0} {}

    void VanguardStage::StartStage() {
        const auto [windowWidth, windowHeight] = GetWorld()->GetWindowSize();
        leftSpawnPosition = Vector2{spawnOffsetX, -100};
        rightSpawnPosition = Vector2{windowWidth - spawnOffsetX, -100};
        SwitchWave();
    }

    void VanguardStage::OnStageFinished() {
        TimerManager::Get().ClearTimer(spawnTimerHandler);
        TimerManager::Get().ClearTimer(waveTimerHandler);
    }

    void VanguardStage::SpawnVanguard() {
        GetWorld()->SpawnActor<Vanguard>().lock()->SetPosition(spawnPosition);

        if (++vanguardCounter == vanguardsPerWave) {
            vanguardCounter = 0;
            TimerManager::Get().ClearTimer(spawnTimerHandler);
            spawnTimerHandler = TimerManager::Get().SetTimer(
                GetWeakRef(),
                &VanguardStage::SwitchWave,
                waveInterval,
                false);
        }
    }

    void VanguardStage::SwitchWave() {
        if (waveCounter++ == wavesToSpawn) {
            FinishStage();
            return;
        }

        spawnPosition = spawnPosition == leftSpawnPosition ? rightSpawnPosition : leftSpawnPosition;

        spawnTimerHandler = TimerManager::Get().SetTimer(
            GetWeakRef(),
            &VanguardStage::SpawnVanguard,
            spawnInterval,
            true);
    }
}
