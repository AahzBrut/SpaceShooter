#pragma once
#include "EnemySpaceShip.h"


namespace SpaceShooter {
    class Boss final : public EnemySpaceShip {
        public:
        explicit Boss(World *world);
        void Update(float deltaTime) override;

    private:
        float speed{100};
        float switchDistance{100};
    };
}
