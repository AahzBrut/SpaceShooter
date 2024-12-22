#include "widgets/GameHUD.h"

#include <format>

#include "framework/World.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceShip.h"


namespace SpaceShooter {
    GameHUD::GameHUD(World *world)
        : world{world},
          frameRateLabel{"FPS: "},
          playerScoreIcon{"assets/SpaceShooterRedux/PNG/Power-ups/star_gold.png"},
          playerScoreText{""},
          winLooseText{""},
          finalScoreText{""},
          restartButton{"Restart"},
          quitButton{"Quit"} {
        winLooseText.SetFontSize(64);
        winLooseText.SetVisible(false);
        finalScoreText.SetFontSize(48);
        finalScoreText.SetVisible(false);
        finalScoreText.SetColor(RED);
        restartButton.SetFontSize(32);
        restartButton.SetVisible(false);
        quitButton.SetFontSize(32);
        quitButton.SetVisible(false);

        frameRateLabel.SetFontSize(36);
        frameRateLabel.SetPosition({10, 5});

        const auto [windowWidth, windowHeight] = world->GetWindowSize();
        progressBar.SetSize({200, 30});
        progressBar.SetPosition({20, windowHeight - 40});

        playerScoreText.SetFontSize(36);
        playerScoreIcon.SetPosition({windowWidth - 220, 10});
        playerScoreText.SetPosition({windowWidth - 180, 10});
    }

    void GameHUD::Draw() {
        frameRateLabel.Draw();
        progressBar.Draw();
        playerScoreText.Draw();
        playerScoreIcon.Draw();
        for (auto lifeIcon: playerLives) {
            lifeIcon.Draw();
        }

        winLooseText.Draw();
        finalScoreText.Draw();
        restartButton.Draw();
        quitButton.Draw();
    }

    void GameHUD::Update(const float deltaTime) {
        const auto frameRate = GetFPS();
        frameRateLabel.SetText(std::format("FPS: {}", frameRate));
    }

    bool GameHUD::HandleEvent() {
        winLooseText.HandleEvent();
        finalScoreText.HandleEvent();
        restartButton.HandleEvent();
        quitButton.HandleEvent();
        return HUD::HandleEvent();
    }

    void GameHUD::OnQuitButtonClicked() {
        QuitButtonPressed.Emit();
    }

    void GameHUD::OnRestartButtonClicked() {
        RestartButtonPressed.Emit();
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

    void GameHUD::InitLifeCountWidgets(const Player *const player) {
        const auto [windowWidth, windowHeight] = world->GetWindowSize();
        for (auto i = 0; i < player->GetLifeCount(); ++i) {
            playerLives.emplace(playerLives.end(), "assets/SpaceShooterRedux/PNG/Pickups/playerLife1_blue.png");
            auto &lifeIcon = playerLives.at(i);
            lifeIcon.SetPosition({windowWidth - static_cast<float>(40 * (i + 1)), windowHeight - 40});
        }
    }

    void GameHUD::OnInitialize() {
        if (const auto player = PlayerManager::Get().GetPlayer()) {
            player->ScoreChanged.BindAction(GetWeakRef(), &GameHUD::OnPLayerScoreChanged);
            player->LifeCountChanged.BindAction(GetWeakRef(), &GameHUD::OnPlayerLifeCountChanged);
            OnPLayerScoreChanged(player->GetScore());
            InitLifeCountWidgets(player);
            SubscribeToPlayersEvents();

            restartButton.ButtonClicked.BindAction(GetWeakRef(), &GameHUD::OnRestartButtonClicked);
            quitButton.ButtonClicked.BindAction(GetWeakRef(), &GameHUD::OnQuitButtonClicked);
        }
    }

    void GameHUD::OnPlayerShipHealthChanged([[maybe_unused]] float amount, const float health, const float maxHealth) {
        progressBar.SetValue(health / maxHealth);
    }

    void GameHUD::OnPlayerLifeCountChanged([[maybe_unused]] unsigned int lifeCount) {
        SubscribeToPlayersEvents();
        playerLives.clear();
        InitLifeCountWidgets(PlayerManager::Get().GetPlayer());
    }

    void GameHUD::OnPLayerScoreChanged(const unsigned int score) {
        const auto scoreText = std::format("{:06}", score);
        playerScoreText.SetText(scoreText);
    }

    void GameHUD::GameFinished(const bool playerWon) {
        winLooseText.SetVisible(true);
        finalScoreText.SetVisible(true);
        restartButton.SetVisible(true);
        quitButton.SetVisible(true);

        if (playerWon) {
            winLooseText.SetText("You Won!");
        } else {
            winLooseText.SetText("You Loose!");
        }
        finalScoreText.SetText(std::format("{:06}", PlayerManager::Get().GetPlayer()->GetScore()));

        const auto [windowWidth, windowHeight] = world->GetWindowSize();

        winLooseText.SetPosition({120, windowHeight * .2f});
        finalScoreText.SetPosition({200, windowHeight *.3f});
        restartButton.SetPosition({200, windowHeight *.4f});
        quitButton.SetPosition({200, windowHeight *.5f});
    }
}
