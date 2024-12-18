#pragma once
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

        void SubscribeToPlayersEvents();
        void OnInitialize() override;
        void OnPlayerShipHealthChanged(float amount, float health, float maxHealth);
        void OnPlayerLifeCountChanged(unsigned int lifeCount);
    };
}
