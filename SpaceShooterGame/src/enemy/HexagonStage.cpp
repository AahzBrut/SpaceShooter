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
        GetWorld()->SpawnActor<Hexagon>().lock()->SetPosition(leftSpawnPosition);
        GetWorld()->SpawnActor<Hexagon>().lock()->SetPosition(rightSpawnPosition);
        GetWorld()->SpawnActor<Hexagon>().lock()->SetPosition(leftSpawnPosition + spawnSideOffset);

        if (++waveCount == waveAmount) FinishStage();
    }
}
