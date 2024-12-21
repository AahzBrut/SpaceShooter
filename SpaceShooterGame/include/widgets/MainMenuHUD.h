#pragma once
#include "widgets/Button.h"
#include "widgets/HUD.h"
#include "widgets/ImageWidget.h"
#include "widgets/TextWidget.h"


namespace SpaceShooter {
    class World;

    class MainMenuHUD final : public HUD {
    public:
        explicit MainMenuHUD(World *world);

        void Draw() override;
        bool HandleEvent() override;

        Delegate<> StartButtonPressed;
        Delegate<> QuitButtonPressed;

    private:
        World *world;
        ImageWidget backgroundImage;
        ImageWidget titleImage;
        TextWidget titleText;
        Button startButton;
        Button quitButton;

        void OnInitialize() override;
        void EmitStartButtonPressed();
        void EmitQuitButtonPressed();
    };
}
