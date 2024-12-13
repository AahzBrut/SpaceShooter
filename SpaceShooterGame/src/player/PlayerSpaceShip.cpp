#include "player/PlayerSpaceShip.h"

#include <cmath>

#include "player/Reward.h"
#include "weapon/FrontalWiper.h"
#include "weapon/ThreeWayShooter.h"

namespace SpaceShooter {
    PlayerSpaceShip::PlayerSpaceShip(World *world, const std::string &texturePath)
    : SpaceShip(world, texturePath, CollisionLayers::Player, CollisionLayers::EnemyBullet | CollisionLayers::Enemy | CollisionLayers::Reward),
    bulletShooter{new FrontalWiper(this, 0.1f, {0, -20})} {
        SetRotation(-90);
        CenterPivotOffset();
   }

    void PlayerSpaceShip::Update(const float deltaTime) {
        SpaceShip::Update(deltaTime);
        HandleInput();
        ConsumeInput(deltaTime);
    }

    void PlayerSpaceShip::ClampInputOnEdge() {
        const auto [windowWidth, windowHeight] = GetWindowSize();
        const auto [currentX, currentY] = GetTransform().position;
        if (currentX < 0.0f && moveInput.x < 0.0f) moveInput.x = 0.f;
        if (currentX > windowWidth && moveInput.x > 0.f) moveInput.x = 0.f;
        if (currentY < 0.0f && moveInput.y < 0.0f) moveInput.y = 0.f;
        if (currentY > windowHeight && moveInput.y > 0.f) moveInput.y = 0.f;
    }

    void PlayerSpaceShip::Shoot() {
        if (bulletShooter) {
            bulletShooter->Shoot();
        }
    }

    void PlayerSpaceShip::SetShooter(Unique<Shooter> &&shooter) {
        bulletShooter = std::move(shooter);
    }

    void PlayerSpaceShip::HandleInput() {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Shoot();
        }

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
        ClampInputOnEdge();
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
