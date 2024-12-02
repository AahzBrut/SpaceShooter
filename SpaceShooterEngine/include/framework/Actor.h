#pragma once
#include "raylib.h"
#include <string>
#include "Object.h"

namespace SpaceShooter {
    class World;

    // ReSharper disable once CppClassCanBeFinal
    class Actor : public Object {
    public:
        explicit Actor(World *world, const std::string &texturePath = "");
        ~Actor() override;

        void SetTexture(const std::string &texturePath);
        void InitializeInternal();
        void UpdateInternal(float deltaTime);
        void Render() const;

        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}

    private:
        World *world;
        bool initialized = false;
        Texture2D texture{};
    };
}
