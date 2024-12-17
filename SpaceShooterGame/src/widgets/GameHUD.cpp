#include "widgets/GameHUD.h"

#include <format>


namespace SpaceShooter {
    GameHUD::GameHUD()
        : frameRateLabel{"FPS: "} {
        frameRateLabel.SetFontSize(36);
        frameRateLabel.SetPosition({10, 5});
    }

    void GameHUD::Draw() {
        frameRateLabel.Draw();
    }

    void GameHUD::Update(const float deltaTime) {
        const auto frameRate = GetFPS();
        frameRateLabel.SetText(std::format("FPS: {}", frameRate));
    }
}
