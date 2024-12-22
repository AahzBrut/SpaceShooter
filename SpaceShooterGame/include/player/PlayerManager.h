#pragma once
#include "Player.h"
#include "framework/Core.h"


namespace SpaceShooter {
    class PlayerManager {
    public:
        static PlayerManager &Get();

        Player& CreateNewPlayer();
        Player* GetPlayer(int index = 0);
        [[nodiscard]] const Player* GetPlayer(int index = 0) const;
        void DeletePlayer(int index = 0);

    protected:
        PlayerManager() = default;

    private:
        static Unique<PlayerManager> playerManager;
        List<Player> players;
    };
}
