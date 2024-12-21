#include "widgets/MainMenuHUD.h"

#include "framework/World.h"


namespace SpaceShooter {
    MainMenuHUD::MainMenuHUD(World *world)
        : world{world},
          backgroundImage{"assets/SpaceShooterRedux/mainMenuBg.png"},
          titleImage{"assets/SpaceShooterRedux/PNG/playerShip3_blue.png"},
          titleText{"Space Shooter"},
          startButton{"START GAME"},
          quitButton{"QUIT GAME"} {}

    void MainMenuHUD::Draw() {
        backgroundImage.Draw();
        titleText.Draw();
        titleImage.Draw();
        startButton.Draw();
        quitButton.Draw();
    }

    bool MainMenuHUD::HandleEvent() {
        startButton.HandleEvent();
        quitButton.HandleEvent();
        return false;
    }

    void MainMenuHUD::OnInitialize() {
        backgroundImage.SetPosition({0, 0});
        titleText.SetFontSize(48);
        titleText.SetColor(YELLOW);
        startButton.SetFontSize(36);
        quitButton.SetFontSize(36);
        const auto windowSize = world->GetWindowSize();
        backgroundImage.SetSize(windowSize);
        const auto [textWidth, textHeight] = titleText.GetBounds();
        titleText.SetPosition({(windowSize.x - textWidth) * 0.5f, 10});
        titleImage.SetPosition({(windowSize.x - titleImage.GetSize().x) * 0.5f, 80});
        startButton.SetSize({300, 60});
        startButton.SetPosition({(windowSize.x - startButton.GetSize().x) * 0.5f, 300});
        quitButton.SetSize({300, 60});
        quitButton.SetPosition({(windowSize.x - quitButton.GetSize().x) * 0.5f, 450});
    }
}
