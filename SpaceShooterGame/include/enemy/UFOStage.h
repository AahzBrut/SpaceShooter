#pragma once
#include <raylib.h>

#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"

namespace SpaceShooter {
    class UFOStage final : public GameStage {
    public:
        explicit UFOStage(World *world);

        void StartStage() override;
        void Update(float deltaTime) override;

    private:
        int spawnAmount{10};
        int spawnCount{0};

        float spawnInterval{5};
        float speed{200};

        TimerHandler spawnTimer;

        void OnStageFinished() override;
        Vector2 GetRandomSpawnPosition(const Vector2& size);
        void SpawnUFO();
    };
}
