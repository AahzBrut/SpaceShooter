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
        return LoadAsset(path, textures, LoadTexture);
    }

    void AssetsManager::CleanCycle() {
        CleanUnusedAssets(textures, UnloadTexture);
        CleanUnusedAssets(fonts, UnloadFont);
        CleanUnusedAssets(sounds, UnloadSound);
    }

    Shared<Font> AssetsManager::GetFont(const std::string &path) {
        return LoadAsset(path, fonts, LoadFont);
    }

    Shared<Sound> AssetsManager::GetSound(const std::string &path) {
        return LoadAsset(path, sounds, LoadSound);
    }
}
