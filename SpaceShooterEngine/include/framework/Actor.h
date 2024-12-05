#pragma once
#include <raylib.h>
#include <string>

#include "Core.h"
#include "Object.h"
#include "Transform.h"
#include <box2d/box2d.h>

namespace SpaceShooter {
    class World;

    class Actor : public Object {
    public:
        explicit Actor(World *world, const std::string &texturePath = "");
        ~Actor() override;

        void SetTexture(const std::string &texturePath);
        void InitializeInternal();
        void UpdateInternal(float deltaTime);
        void Render() const;

        [[nodiscard]] Vector2 Position() const;
        void SetPosition(const Vector2 &position);
        void SetPositionOffset(const Vector2 &position);
        [[nodiscard]] float Rotation() const;
        void SetRotation(float rotation);
        void SetRotationOffset(float rotation);
        [[nodiscard]] float Scale() const;
        void SetScale(float scale);
        void SetScaleOffset(float scale);
        [[nodiscard]] Vector2 GetForwardVector() const;
        [[nodiscard]] Vector2 GetRightVector() const;
        void CenterPivotOffset();
        [[nodiscard]] Vector2 GetTextureSize() const;
        [[nodiscard]] Vector2 GetWindowSize() const;
        [[nodiscard]] Transform GetTransform() const;
        [[nodiscard]] World *GetWorld() const { return world; }
        [[nodiscard]] bool IsOutOfWindowBounds() const;
        [[nodiscard]] Vector2 GetSize() const { return size; }
        void SetPhysicsEnabled(bool enablePhysics);
        void UpdatePhysicsBodyTransform() const;

        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}

    private:
        World *world;
        bool initialized = false;
        Shared<Texture2D> texture{};
        Transform transform{};
        Vector2 pivotOffset{};
        Rectangle textureRect{};
        Vector2 size{};
        b2BodyId bodyId{};
        bool physicsEnabled{false};

        void InitializePhysics();
        void UnInitializePhysics();
    };
}
