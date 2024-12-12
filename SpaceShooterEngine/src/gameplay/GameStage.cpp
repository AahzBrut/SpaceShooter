#include "gameplay/GameStage.h"

namespace SpaceShooter {
    GameStage::GameStage(World *world) : world{world}, stageFinished{false} {}

    void GameStage::StartStage() {}

    void GameStage::Update(float deltaTime) {}

    void GameStage::FinishStage() {
        stageFinished = true;
        OnStageFinished();
        StageFinished.Emit();
    }

    void GameStage::OnStageFinished() {}
}
