#include "raylib.h"
#include "framework/Actor.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"

namespace SpaceShooter {
    Actor::Actor(World *world, const std::string &texturePath) : world{world} {
        SetTexture(texturePath);
    }

    void Actor::SetTexture(const std::string &texturePath) {
        texture = AssetsManager::Get().GetTexture(texturePath);
    }

    Actor::~Actor() {
        LOG("Destroying Actor");
    }

    void Actor::InitializeInternal() {
        LOG("Initializing Actor");
        Initialize();
    }

    void Actor::UpdateInternal(const float deltaTime) {
        if (IsPendingDestruction()) return;

        Update(deltaTime);
    }

    void Actor::Render() const {
        if (IsPendingDestruction()) return;

        DrawTexture(*texture, 0, 0, WHITE);
    }
}
