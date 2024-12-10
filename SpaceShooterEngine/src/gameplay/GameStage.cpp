#include "gameplay/GameStage.h"

#include "framework/Core.h"
#include "framework/World.h"

namespace SpaceShooter {
    GameStage::GameStage(World *world) : world{world}, stageFinished{false} {}

    void GameStage::Initialize() {
        LOG("Initializing GameStage");
    }

    void GameStage::Update(float deltaTime) {
        LOG("Updating GameStage");
    }

    void GameStage::FinishStage() {
        LOG("Finishing GameStage");
        StageFinished.Emit();
        stageFinished = true;
        OnStageFinished();
    }

    void GameStage::OnStageFinished() {
        LOG("Stage finished");
    }
}
