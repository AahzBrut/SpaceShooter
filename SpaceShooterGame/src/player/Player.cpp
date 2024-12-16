#include "player/Player.h"

#include "framework/World.h"
#include "player/PlayerSpaceShip.h"


namespace SpaceShooter {
    Weak<PlayerSpaceShip> Player::SpawnSpaceship(World *world) {
        if (lifeCount > 0) {
            --lifeCount;
            const auto [windowWidth, windowHeight] = world->GetWindowSize();
            spaceShip = world->SpawnActor<PlayerSpaceShip>();
            spaceShip.lock()->SetPosition({windowWidth * 0.5f, windowHeight * 0.9f});
            LifeCountChanged.Emit(lifeCount);
            return spaceShip;
        }
        LifeCountDepleted.Emit();
        return Weak<PlayerSpaceShip>{};
    }

    void Player::AddLifeCount(const unsigned int count) {
        if (count == 0) return;

        lifeCount += count;
        LifeCountChanged.Emit(lifeCount);
    }

    void Player::AddScore(const unsigned int score) {
        if (score == 0) return;

        this->score += score;
        ScoreChanged.Emit(this->score);
    }
}
