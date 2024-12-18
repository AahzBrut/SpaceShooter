#include "widgets/GameHUD.h"

#include <format>

#include "player/PlayerManager.h"
#include "player/PlayerSpaceShip.h"


namespace SpaceShooter {
    GameHUD::GameHUD()
        : frameRateLabel{"FPS: "} {
        frameRateLabel.SetFontSize(36);
        frameRateLabel.SetPosition({10, 5});
        progressBar.SetPosition({200, 10});
    }

    void GameHUD::Draw() {
        frameRateLabel.Draw();
        progressBar.Draw();
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
            SubscribeToPlayersEvents();
        }
    }

    void GameHUD::OnPlayerShipHealthChanged([[maybe_unused]] float amount, const float health, const float maxHealth) {
        progressBar.SetValue(health / maxHealth);
    }

    void GameHUD::OnPlayerLifeCountChanged([[maybe_unused]] unsigned int lifeCount) {
        SubscribeToPlayersEvents();
    }
}
