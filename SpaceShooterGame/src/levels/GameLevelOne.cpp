#include "levels/GameLevelOne.h"

#include "enemy/Vanguard.h"
#include "player/PlayerSpaceShip.h"

namespace SpaceShooter {
    GameLevelOne::GameLevelOne(Application *application) : World(application){
        const auto enemySpaceShip = SpawnActor<Vanguard>();
        enemySpaceShip.lock()->SetPosition(Vector2{100, 100});
        const auto playerShip = SpawnActor<PlayerSpaceShip>();
        playerShip.lock()->SetPosition(Vector2{200, 600});
    }
}
