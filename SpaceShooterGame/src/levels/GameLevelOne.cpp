#include "levels/GameLevelOne.h"

#include "enemy/Vanguard.h"
#include "framework/TimerManager.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application){
        const auto enemySpaceShip = SpawnActor<Vanguard>();
        enemySpaceShip.lock()->SetPosition(Vector2{100, 100});
        const auto playerShip = SpawnActor<PlayerSpaceShip>();
        playerShip.lock()->SetPosition(Vector2{200, 600});
    }

    void GameLevelOne::Initialize() {
        timerIndex = TimerManager::Get().SetTimer(GetWeakRef(), &GameLevelOne::OnTimerTimeout, 1, true);
    }

    void GameLevelOne::OnTimerTimeout() {
        const auto enemySpaceShip = SpawnActor<Vanguard>();
        enemySpaceShip.lock()->SetPosition(Vector2{300, 100});

        static int counter = 0;
        counter++;
        if (counter  == 5) {
            TimerManager::Get().ClearTimer(timerIndex);
        }
    }
}
