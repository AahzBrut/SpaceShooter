#include "enemy/ChaosStage.h"

#include "enemy/Hexagon.h"
#include "enemy/TweenBlade.h"
#include "enemy/UFO.h"
#include "enemy/Vanguard.h"
#include "framework/MathUtility.h"
#include "framework/World.h"


namespace SpaceShooter {
    ChaosStage::ChaosStage(World *world)
        : GameStage(world) {}

    void ChaosStage::StartStage() {
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::SpawnVanguard, spawnInterval);
        difficultyTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::IncreaseDifficulty,
                                                       spawnIntervalDecrementInterval, true);
        TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::StageDurationReached, stageDuration);
    }

    void ChaosStage::OnStageFinished() {
        TimerManager::Get().ClearTimer(spawnTimer);
        TimerManager::Get().ClearTimer(difficultyTimer);
    }

    void ChaosStage::SpawnVanguard() {
        const auto newVanguard = GetWorld()->SpawnActor<Vanguard>();
        newVanguard.lock()->SetPosition(GetRandomSpawnPositionTop());
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::SpawnTweenBlade, spawnInterval);
    }

    void ChaosStage::SpawnTweenBlade() {
        const auto newTweenBlade = GetWorld()->SpawnActor<TweenBlade>();
        newTweenBlade.lock()->SetPosition(GetRandomSpawnPositionTop());
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::SpawnHexagon, spawnInterval);
    }

    void ChaosStage::SpawnHexagon() {
        const auto newHexagon = GetWorld()->SpawnActor<Hexagon>();
        newHexagon.lock()->SetPosition(GetRandomSpawnPositionTop());
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::SpawnUFO, spawnInterval);
    }

    void ChaosStage::SpawnUFO() {
        const auto newUfo = GetWorld()->SpawnActor<UFO>();

        const auto spawnPosition = GetRandomSpawnPositionSide();
        const auto centerPosition = GetWorld()->GetWindowSize() * 0.5f;
        const auto velocity = NormalizedVector(centerPosition - spawnPosition) * 200;

        newUfo.lock()->SetPosition(spawnPosition);
        newUfo.lock()->SetVelocity(velocity);
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &ChaosStage::SpawnVanguard, spawnInterval);
    }

    void ChaosStage::IncreaseDifficulty() {
        spawnInterval -= spawnIntervalDecrement;
        if (spawnInterval <= minSpawnInterval) {
            spawnInterval = minSpawnInterval;
        }
    }

    void ChaosStage::StageDurationReached() {
        FinishStage();
    }

    Vector2 ChaosStage::GetRandomSpawnPositionTop() const {
        const auto windowWidth = GetWorld()->GetWindowSize().x;
        return {RandomRange(100, windowWidth - 100), -100};
    }

    // ReSharper disable once CppDFAUnreachableFunctionCall
    Vector2 ChaosStage::GetRandomSpawnPositionSide() const {
        constexpr auto minSizeX = 50;
        constexpr auto minSizeY = 50;
        const auto [windowWidth, windowHeight] = GetWorld()->GetWindowSize();
        const auto spawnLeft = RandomRange(-1.f, 1.f);
        const auto spawnLocX = spawnLeft < 0 ? windowWidth + minSizeX : - minSizeX;
        const auto spawnLocY = RandomRange(minSizeY, windowHeight - minSizeY);
        return Vector2{spawnLocX, spawnLocY};
    }
}
