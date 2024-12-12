#include "enemy/TweenBladeStage.h"

#include "enemy/TweenBlade.h"
#include "framework/World.h"

namespace SpaceShooter {
    TweenBladeStage::TweenBladeStage(World *world)
        : GameStage(world) {}

    void TweenBladeStage::StartStage() {
        const auto [windowWidth, _] = GetWorld()->GetWindowSize();
        leftSpawnPosition = Vector2{windowWidth * 0.5f - spawnDistanceFromCenter, -150.f};
        rightSpawnPosition = Vector2{windowWidth * 0.5f + spawnDistanceFromCenter, -150.f};
        SpawnTweenBlade();
    }

    void TweenBladeStage::SpawnTweenBlade() {
        if (spawnCount == spawnAmount) {
            FinishStage();
            return;
        }

        spawnPosition = spawnCount % 2 == 0 ? leftSpawnPosition : rightSpawnPosition;
        spawnCount++;

        const auto vanguard = GetWorld()->SpawnActor<TweenBlade>();
        vanguard.lock()->SetPosition(spawnPosition);

        spawnTimerHandler = TimerManager::Get().SetTimer(
            GetWeakRef(),
            &TweenBladeStage::SpawnTweenBlade,
            spawnInterval,
            false);
    }

    void TweenBladeStage::OnStageFinished() {
        TimerManager::Get().ClearTimer(spawnTimerHandler);
    }
}
