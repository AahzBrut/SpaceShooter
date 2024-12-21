#include "enemy/Boss.h"


namespace SpaceShooter {
    Boss::Boss(World *world) : EnemySpaceShip{world, "assets/SpaceShooterRedux/PNG/Boss.png"} {
        SetRotation(90);
        CenterPivotOffset();
    }

    void Boss::Update(const float deltaTime) {
        EnemySpaceShip::Update(deltaTime);
    }
}
