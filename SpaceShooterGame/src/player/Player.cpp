#include "player/Player.h"

#include "framework/World.h"
#include "player/PlayerSpaceShip.h"


namespace SpaceShooter {
    Weak<PlayerSpaceShip> Player::SpawnSpaceship(World *world) {
        if (--lifeCount > 0) {
            const auto [windowWidth, windowHeight] = world->GetWindowSize();
            spaceShip = world->SpawnActor<PlayerSpaceShip>();
            spaceShip.lock()->SetPosition({windowWidth * 0.5f, windowHeight * 0.9f});
            LifeCountChanged.Emit(lifeCount);
            return spaceShip;
        }
        LifeCountChanged.Emit(lifeCount);
        LifeCountDepleted.Emit();
        return Weak<PlayerSpaceShip>{};
    }

    void Player::AddLifeCount(const unsigned int count) {
        if (count == 0) return;

        lifeCount += count;
        LifeCountChanged.Emit(lifeCount);
    }

    void Player::AddScore(const unsigned int amount) {
        if (amount == 0) return;

        score += amount;
        ScoreChanged.Emit(score);
    }
}
