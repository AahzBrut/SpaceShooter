#pragma once
#include "widgets/HUD.h"
#include "widgets/TextWidget.h"


namespace SpaceShooter {
    class GameHUD final : public HUD {
        public:
        GameHUD();

        void Draw() override;
        void Update(float deltaTime) override;

    private:
        TextWidget frameRateLabel;
    };
}
