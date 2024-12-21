#pragma once
#include "framework/World.h"


namespace SpaceShooter {
    class MainMenuHUD;

    class MainMenu final : public World {
    public:
        explicit MainMenu(Application *application);

    private:
        Weak<MainMenuHUD> menuHUD;

        void Initialize() override;
        void StartGame();
        void QuitGame();
    };
}
