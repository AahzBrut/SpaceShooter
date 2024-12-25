#include "framework/BackgroundLayer.h"

#include "framework/AssetsManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"


namespace SpaceShooter {
    BackgroundLayer::BackgroundLayer(World *world,
                                     const List<std::string> &texturePaths,
                                     const Vector2 &minVelocity,
                                     const Vector2 &maxVelocity,
                                     const float minSize,
                                     const float maxSize,
                                     const float minRotationSpeed,
                                     const float maxRotationSpeed,
                                     const int spriteCount,
                                     const Color &tintColor)
        : Actor{world},
          minVelocity{minVelocity},
          maxVelocity{maxVelocity},
          minSize{minSize},
          maxSize{maxSize},
          minRotationSpeed{minRotationSpeed},
          maxRotationSpeed{maxRotationSpeed},
          spritesCount{spriteCount},
          tintColor{tintColor} {
        SetAssets(texturePaths);
        InitSprites(world->GetWindowSize());
    }

    void BackgroundLayer::SetAssets(const List<std::string> &texturePaths) {
        auto &assetManager = AssetsManager::Get();
        for (auto &texturePath: texturePaths) {
            textures.push_back(assetManager.GetTexture(texturePath));
        }
    }

    void BackgroundLayer::InitSprites(const Vector2 &windowSize) {
        for (auto index = 0; index < spritesCount; index++) {
            auto transform = Transform{};
            transform.position = Vector2{RandomRange(0, windowSize.x), RandomRange(-100, windowSize.y + 100)};
            transform.rotation = RandomRange(minRotationSpeed, maxRotationSpeed);
            transform.scale = RandomRange(minSize, maxSize);
            sprites.push_back(Sprite{
                Vector2{RandomRange(minVelocity.x, maxVelocity.x), RandomRange(minVelocity.y, maxVelocity.y)},
                RandomRange(minSize, maxSize),
                RandomRange(minRotationSpeed, maxRotationSpeed),
                GetRandomTexture(),
                transform
            });
        }
    }

    void BackgroundLayer::Update(const float deltaTime) {
        if (IsPendingDestruction()) return;
        const auto windowSize = GetWindowSize();
        for (auto &sprite: sprites) {
            sprite.transform.position += sprite.velocity * deltaTime;
            sprite.transform.rotation += sprite.rotationSpeed * deltaTime;
            if (sprite.transform.position.y > windowSize.y + 100) {
                sprite.transform.position.y = -100;
            }
        }
    }

    void BackgroundLayer::Render() const {
        if (IsPendingDestruction()) return;
        for (const auto &sprite: sprites) {
            const auto [spriteWidth, spriteHeight] = Vector2{
                static_cast<float>(sprite.texture->width), static_cast<float>(sprite.texture->height)
            };
            const auto destRect = Rectangle(
                sprite.transform.position.x - spriteWidth * 0.5f * sprite.transform.scale,
                sprite.transform.position.y - spriteHeight * 0.5f * sprite.transform.scale,
                spriteWidth * sprite.transform.scale,
                spriteHeight * sprite.transform.scale);
            DrawTexturePro(
                *sprite.texture,
                {0, 0, spriteWidth, spriteHeight},
                destRect,
                {spriteWidth, spriteHeight},
                sprite.transform.rotation,
                tintColor
            );
        }
    }

    const Shared<Texture2D> &BackgroundLayer::GetRandomTexture() const {
        const auto index = RandomIntRange(0, static_cast<int>(textures.size() - 1));
        return textures[index];
    }
}
