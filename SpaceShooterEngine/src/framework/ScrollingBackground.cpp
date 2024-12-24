#include "framework/ScrollingBackground.h"

#include "framework/World.h"


namespace SpaceShooter {
    ScrollingBackground::ScrollingBackground(World *world, const std::string &texturePath, const float scrollSpeed)
        : Actor(world, texturePath),
          scrollSpeed{scrollSpeed} {
        SetSize(world->GetWindowSize());
    }

    void ScrollingBackground::Render() const {
        if (IsPendingDestruction()) return;
        const auto &texture = GetTexture();
        const auto [destWidth, destHeight] = GetSize();

        const auto destRect = Rectangle(
            0,
            0,
            destWidth,
            destHeight);
        DrawTexturePro(texture, {0, currentOffset, destWidth, destHeight}, destRect,
                       {0, 0}, 0.f,
                       color);
    }

    void ScrollingBackground::Update(const float deltaTime) {
        currentOffset += deltaTime * scrollSpeed;
    }
}
