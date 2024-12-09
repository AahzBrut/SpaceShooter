#pragma once
#include "spaceShip/SpaceShip.h"

namespace SpaceShooter {
    class EnemySpaceShip : public SpaceShip {
    public:
        EnemySpaceShip(World *world, const std::string &texturePath, float collisionDamage = 200.f);

        void Update(float deltaTime) override;
        void OnContactBegin(Actor *actor) override;

    private:
        float collisionDamage;
    };
}
