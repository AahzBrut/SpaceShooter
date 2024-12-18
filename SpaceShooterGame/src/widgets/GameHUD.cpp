#include "widgets/GameHUD.h"

#include <format>

#include "framework/World.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceShip.h"


namespace SpaceShooter {
    GameHUD::GameHUD(World *world)
        : world{world},
          frameRateLabel{"FPS: "} {
        frameRateLabel.SetFontSize(36);
        frameRateLabel.SetPosition({10, 5});

        const auto [windowWidth, windowHeight] = world->GetWindowSize();
        progressBar.SetSize({200, 30});
        progressBar.SetPosition({20, windowHeight - 40});
    }

    void GameHUD::Draw() {
        frameRateLabel.Draw();
        progressBar.Draw();
        for (auto lifeIcon: playerLives) {
            lifeIcon.Draw();
        }
    }

    void GameHUD::Update(const float deltaTime) {
        const auto frameRate = GetFPS();
        frameRateLabel.SetText(std::format("FPS: {}", frameRate));
    }

    void GameHUD::SubscribeToPlayersEvents() {
        if (const auto player = PlayerManager::Get().GetPlayer()) {
            if (const auto playerShip = player->GetSpaceship(); !playerShip.expired()) {
                auto &healthComponent = playerShip.lock()->GetHealthComponent();
                healthComponent.HealthChanged.BindAction(GetWeakRef(), &GameHUD::OnPlayerShipHealthChanged);
                OnPlayerShipHealthChanged(0, healthComponent.GetHealth(), healthComponent.GetMaxHealth());
            }
        }
    }

    void GameHUD::OnInitialize() {
        if (const auto player = PlayerManager::Get().GetPlayer()) {
            player->LifeCountChanged.BindAction(GetWeakRef(), &GameHUD::OnPlayerLifeCountChanged);
            const auto [windowWidth, windowHeight] = world->GetWindowSize();
            for (auto i = 0; i < player->GetLifeCount(); ++i) {
                playerLives.emplace(
                    playerLives.end(),
                    ImageWidget{"assets/SpaceShooterRedux/PNG/Pickups/playerLife1_blue.png"}
                );
                auto &lifeIcon = playerLives.at(i);
                lifeIcon.SetPosition({windowWidth - 40 * (i + 1), windowHeight - 40});
            }
            SubscribeToPlayersEvents();
        }
    }

    void GameHUD::OnPlayerShipHealthChanged([[maybe_unused]] float amount, const float health, const float maxHealth) {
        progressBar.SetValue(health / maxHealth);
    }

    void GameHUD::OnPlayerLifeCountChanged([[maybe_unused]] unsigned int lifeCount) {
        SubscribeToPlayersEvents();
        playerLives.erase(playerLives.end());
    }
}
