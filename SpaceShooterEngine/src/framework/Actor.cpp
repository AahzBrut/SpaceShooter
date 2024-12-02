#include "raylib.h"
#include "framework/Actor.h"
#include "framework/Core.h"

namespace SpaceShooter {
    Actor::Actor(World *world, const std::string &texturePath) : world{world} {
        SetTexture(texturePath);
    }

    void Actor::SetTexture(const std::string &texturePath) {
        texture = LoadTexture(texturePath.c_str());
    }

    Actor::~Actor() {
        LOG("Destroying Actor");
        UnloadTexture(texture);
    }

    void Actor::InitializeInternal() {
        LOG("Initializing Actor");
        Initialize();
    }

    void Actor::UpdateInternal(const float deltaTime) {
        LOG("Updating Actor");
        Update(deltaTime);
    }

    void Actor::Render() const {
        DrawTexture(texture, 0, 0, WHITE);
    }
}
