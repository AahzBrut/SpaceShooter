#include "enemy/UFOStage.h"

#include "enemy/UFO.h"
#include "framework/MathUtility.h"
#include "framework/World.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "weapon/BulletShooter.h"


namespace SpaceShooter {
    UFOStage::UFOStage(World *world): GameStage(world) {}

    void UFOStage::StartStage() {
        spawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &UFOStage::SpawnUFO, spawnInterval, true);
    }

    void UFOStage::Update(const float deltaTime) {}

    void UFOStage::OnStageFinished() {
        TimerManager::Get().ClearTimer(spawnTimer);
    }

    // ReSharper disable once CppDFAUnreachableFunctionCall
    Vector2 UFOStage::GetRandomSpawnPosition(const Vector2& size) {
        const auto [windowWidth, windowHeight] = GetWorld()->GetWindowSize();
        const auto spawnLeft = RandomRange(-1.f, 1.f);
        const auto spawnLocX = spawnLeft < 0 ? windowWidth + size.x : - size.x;
        const auto spawnLocY = RandomRange(size.y, windowHeight - size.y);
        return Vector2{spawnLocX, spawnLocY};
    }

    void UFOStage::SpawnUFO() {
        const auto ufo = GetWorld()->SpawnActor<UFO>();
        const auto ufoSize = ufo.lock()->GetSize();
        const auto spawnPosition = GetRandomSpawnPosition(ufoSize);
        ufo.lock()->SetPosition(spawnPosition);

        const auto centerPosition = GetWorld()->GetWindowSize() * .5f;
        auto directionToCenter = centerPosition - spawnPosition;
        NormalizeVector(directionToCenter);
        ufo.lock()->SetVelocity(directionToCenter * speed);

        if (++spawnCount == spawnAmount) {
            FinishStage();
        }
    }
}
