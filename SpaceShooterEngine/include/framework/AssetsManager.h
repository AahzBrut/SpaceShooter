#pragma once
#include "Core.h"
#include <raylib.h>

namespace SpaceShooter {
    class AssetsManager {
    public:
        static AssetsManager& Get();
        Shared<Texture2D> GetTexture(const std::string& path);
        void CleanCycle();

    protected:
        AssetsManager() = default;

    private:
        static Unique<AssetsManager> instance;
        Dictionary<std::string, Shared<Texture2D>> textures{};
    };
}
