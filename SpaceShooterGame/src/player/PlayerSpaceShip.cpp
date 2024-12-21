#include "player/PlayerSpaceShip.h"

#include <cmath>

#include "player/Reward.h"
#include "weapon/ThreeWayShooter.h"

using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    PlayerSpaceShip::PlayerSpaceShip(World *world, const std::string &texturePath)
        : SpaceShip(world, texturePath, Player, EnemyBullet | Enemy | CollisionLayers::Reward),
          bulletShooter{new BulletShooter(this, 0.1f, PlayerBullet, Enemy | EnemyBullet)} {
        SetRotation(-90);
        CenterPivotOffset();
    }

    void PlayerSpaceShip::Update(const float deltaTime) {
        SpaceShip::Update(deltaTime);
        HandleInput();
        ConsumeInput(deltaTime);
        UpdateInvulnerabilityFlash(deltaTime);
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
        if (shooter && typeid(*shooter.get()) == typeid(*bulletShooter.get())) {
            bulletShooter->IncreaseLevel(1);
            return;
        }
        bulletShooter = std::move(shooter);
    }

    void PlayerSpaceShip::ApplyDamage(const float amount) {
        if (!invulnerable) SpaceShip::ApplyDamage(amount);
    }

    void PlayerSpaceShip::Initialize() {
        SpaceShip::Initialize();
        invulnerabilityTimer = TimerManager::Get().SetTimer(GetWeakRef(), &PlayerSpaceShip::UndoInvulnerability,
                                                            invulnerabilityTime);
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

    void PlayerSpaceShip::ConsumeInput([[maybe_unused]] float deltaTime) {
        SetVelocity(Vector2{moveInput.x * speed, moveInput.y * speed});
        moveInput = Vector2{};
    }

    void PlayerSpaceShip::UndoInvulnerability() {
        SetColor(WHITE);
        invulnerableFlashDir = -1;
        invulnerable = false;
    }

    void PlayerSpaceShip::UpdateInvulnerabilityFlash(const float deltaTime) {
        if (!invulnerable) return;

        invulnerabilityFlashTimer += deltaTime * invulnerableFlashDir;
        if (invulnerabilityFlashTimer >= invulnerableFlashPeriod) {
            invulnerableFlashDir = -1;
            invulnerabilityFlashTimer = invulnerableFlashPeriod;
        } else if (invulnerabilityFlashTimer <= 0) {
            invulnerableFlashDir = 1;
            invulnerabilityFlashTimer = 0;
        }

        auto currentColor = GetColor();
        const auto alfa = 255 * (invulnerabilityFlashTimer / invulnerableFlashPeriod);
        currentColor.a = static_cast<unsigned char>(alfa);
        SetColor(currentColor);
    }
}
