#include "player/PlayerManager.h"

namespace SpaceShooter {
    Unique<PlayerManager> PlayerManager::playerManager{nullptr};

    PlayerManager &PlayerManager::Get() {
        if (!playerManager) {
            playerManager = Unique<PlayerManager>{new PlayerManager};
        }

        return *playerManager;
    }

    Player &PlayerManager::CreateNewPlayer() {
        players.emplace(players.end(), Player());
        return players.back();
    }

    Player *PlayerManager::GetPlayer(const int index) {
        if (index >= 0 && index < players.size()) {
            return &players[index];
        }
        return nullptr;
    }

    const Player *PlayerManager::GetPlayer(const int index) const {
        if (index >= 0 && index < players.size()) {
            return &players[index];
        }
        return nullptr;
    }
}
