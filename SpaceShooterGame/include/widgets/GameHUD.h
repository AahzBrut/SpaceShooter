#pragma once
#include "player/Player.h"
#include "widgets/Button.h"
#include "widgets/HUD.h"
#include "widgets/ImageWidget.h"
#include "widgets/ProgressBar.h"
#include "widgets/TextWidget.h"


namespace SpaceShooter {
    class World;

    class GameHUD final : public HUD {
    public:
        explicit GameHUD(World* world);

        void Draw() override;
        void Update(float deltaTime) override;

    private:
        World *world;
        TextWidget frameRateLabel;
        ProgressBar progressBar;
        List<ImageWidget> playerLives;
        ImageWidget playerScoreIcon;
        TextWidget playerScoreText;
        Button button;

        void SubscribeToPlayersEvents();
        void InitLifeCountWidgets(const Player *player);
        void OnInitialize() override;
        void OnPlayerShipHealthChanged(float amount, float health, float maxHealth);
        void OnPlayerLifeCountChanged(unsigned int lifeCount);
        void OnPLayerScoreChanged(unsigned int score);
    };
}
