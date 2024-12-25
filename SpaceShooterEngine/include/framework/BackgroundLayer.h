#pragma once
#include "Actor.h"


namespace SpaceShooter {
    class World;

    class BackgroundLayer final : public Actor {
    public:
        explicit BackgroundLayer(World *world,
                                 const List<std::string> &texturePaths = {},
                                 const Vector2 &minVelocity = {0, 50},
                                 const Vector2 &maxVelocity = {0, 200},
                                 float minSize = .5,
                                 float maxSize = 2.5,
                                 float minRotationSpeed = -20,
                                 float maxRotationSpeed = 20,
                                 int spriteCount = 20,
                                 const Color &tintColor = {180, 180, 200, 128});

        void SetAssets(const List<std::string> &texturePaths);
        void InitSprites(const Vector2 &windowSize);
        void Update(float deltaTime) override;
        void Render() const override;

    private:
        Vector2 minVelocity;
        Vector2 maxVelocity;
        float minSize;
        float maxSize;
        float minRotationSpeed;
        float maxRotationSpeed;
        int spritesCount;
        Color tintColor;

        struct Sprite {
            Vector2 velocity;
            float size;
            float rotationSpeed;
            Shared<Texture2D> texture;
            Transform transform;
        };

        List<Shared<Texture2D> > textures;
        List<Sprite> sprites;

        const Shared<Texture2D> &GetRandomTexture() const;
    };
}
