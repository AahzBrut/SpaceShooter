#include "gameplay/GameStage.h"

namespace SpaceShooter {
    GameStage::GameStage(World *world) : world{world}, stageFinished{false} {}

    void GameStage::Initialize() {}

    void GameStage::Update(float deltaTime) {}

    void GameStage::FinishStage() {
        StageFinished.Emit();
        stageFinished = true;
        OnStageFinished();
    }

    void GameStage::OnStageFinished() {}
}
