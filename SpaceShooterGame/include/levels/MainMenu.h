#pragma once
#include "framework/World.h"
#include "widgets/MainMenuHUD.h"


namespace SpaceShooter {
    class MainMenu final : public World {
    public:
        explicit MainMenu(Application *application);

    private:
        Weak<MainMenuHUD> menuHUD;

        void Initialize() override;
    };
}
