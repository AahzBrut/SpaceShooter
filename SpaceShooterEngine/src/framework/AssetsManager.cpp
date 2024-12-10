#include "framework/AssetsManager.h"

#include "raylib.h"

namespace SpaceShooter {
    Unique<AssetsManager> AssetsManager::instance{nullptr};

    AssetsManager &AssetsManager::Get() {
        if (!instance) {
            instance = Unique<AssetsManager>{new AssetsManager};
        }
        return *instance;
    }

    Shared<Texture2D> AssetsManager::GetTexture(const std::string &path) {
        if (const auto texture = textures.find(path); texture != textures.end()) {
            return texture->second;
        }
        const auto texture = std::make_shared<Texture2D>(LoadTexture(path.c_str()));
        textures.insert({path, texture});
        return texture;
    }

    void AssetsManager::CleanCycle() {
        LOG("Starting cleaning cycle.");
        for (auto iterator = textures.begin(); iterator != textures.end();) {
            if (iterator->second.unique()) {
                UnloadTexture(*iterator->second);
                iterator = textures.erase(iterator);
            } else {
                ++iterator;
            }
        }
    }
}
