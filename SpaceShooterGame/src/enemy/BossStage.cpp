#include "enemy/BossStage.h"

#include "enemy/Boss.h"
#include "framework/World.h"
#include "weapon/BulletShooter.h"

namespace SpaceShooter {
    BossStage::BossStage(World *world)
        : GameStage{world} {}

    void BossStage::StartStage() {
        const auto boss = GetWorld()->SpawnActor<Boss>();
        boss.lock()->SetPosition({GetWorld()->GetWindowSize().x * .5f, 150});
        boss.lock()->Destroyed.BindAction(GetWeakRef(), &BossStage::OnBossDestroyed);
    }

    void BossStage::OnBossDestroyed([[maybe_unused]] Actor *bossActor) {
        LOG("BossStage::OnBossDestroyed");
        FinishStage();
    }
}
