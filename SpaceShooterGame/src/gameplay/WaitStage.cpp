#include "gameplay/WaitStage.h"

#include "framework/TimerManager.h"

namespace SpaceShooter {
    WaitStage::WaitStage(World *world, const float waitDuration)
    : GameStage(world), waitDuration(waitDuration){}

    void WaitStage::Initialize() {
        TimerManager::Get().SetTimer(GetWeakRef(), &WaitStage::FinishStage, waitDuration);
    }
}
