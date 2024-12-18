#pragma once
#include "widgets/HUD.h"
#include "widgets/ProgressBar.h"
#include "widgets/TextWidget.h"


namespace SpaceShooter {
    class GameHUD final : public HUD {
    public:
        GameHUD();

        void Draw() override;
        void Update(float deltaTime) override;

    private:
        TextWidget frameRateLabel;
        ProgressBar progressBar;

        void SubscribeToPlayersEvents();
        void OnInitialize() override;
        void OnPlayerShipHealthChanged(float amount, float health, float maxHealth);
        void OnPlayerLifeCountChanged(unsigned int lifeCount);
    };
}
