#include "enemy/HexagonStage.h"

#include "enemy/Hexagon.h"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    HexagonStage::HexagonStage(World *world) : GameStage(world) {}

    void HexagonStage::StartStage() {
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &HexagonStage::SpawnHexagon, spawnInterval, true);
    }

    void HexagonStage::OnStageFinished() {
        TimerManager::Get().ClearTimer(spawnTimer);
    }

    void HexagonStage::SpawnHexagon() {
        auto hexagon = GetWorld()->SpawnActor<Hexagon>();
        hexagon.lock()->SetPosition(leftSpawnPosition);

        hexagon = GetWorld()->SpawnActor<Hexagon>();
        hexagon.lock()->SetPosition(rightSpawnPosition);

        hexagon = GetWorld()->SpawnActor<Hexagon>();
        hexagon.lock()->SetPosition(leftSpawnPosition + spawnSideOffset);

        if (++waveCount == waveAmount) {
            FinishStage();
        }
    }
}
