#include "player/PlayerSpaceShip.h"

#include <cmath>

namespace SpaceShooter {
    PlayerSpaceShip::PlayerSpaceShip(World *world, const std::string &texturePath): SpaceShip(world, texturePath) {}

    void PlayerSpaceShip::Update(const float deltaTime) {
        SpaceShip::Update(deltaTime);
        HandleInput();
        ConsumeInput(deltaTime);
    }

    void PlayerSpaceShip::HandleInput() {
        if (IsKeyDown(KEY_W)) {
            moveInput.y = -1.f;
        } else if (IsKeyDown(KEY_S)) {
            moveInput.y = 1.f;
        }
        if (IsKeyDown(KEY_A)) {
            moveInput.x = -1.f;
        } else if (IsKeyDown(KEY_D)) {
            moveInput.x = 1.f;
        }
        if (moveInput.x == 0 && moveInput.y == 0) return;

        const auto length = std::sqrt(moveInput.x * moveInput.x + moveInput.y * moveInput.y);

        moveInput.x = moveInput.x / length;
        moveInput.y = moveInput.y / length;
    }

    void PlayerSpaceShip::ConsumeInput(float deltaTime) {
        SetVelocity(Vector2{moveInput.x * speed, moveInput.y * speed});
        moveInput = Vector2{};
    }
}
