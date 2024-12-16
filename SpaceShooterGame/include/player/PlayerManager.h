#pragma once
#include "Player.h"
#include "framework/Core.h"


namespace SpaceShooter {
    class PlayerManager {
    public:
        static PlayerManager &Get();

        Player& CreateNewPlayer();
        Player* GetPlayer(int index = 0);
        const Player* GetPlayer(int index = 0) const;

    protected:
        PlayerManager() = default;

    private:
        static Unique<PlayerManager> playerManager;
        List<Player> players;
    };
}
