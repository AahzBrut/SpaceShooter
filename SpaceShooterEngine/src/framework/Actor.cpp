#include "raylib.h"
#include "framework/Actor.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"
#include "framework/MathUtility.h"

namespace SpaceShooter {
    Actor::Actor(World *world, const std::string &texturePath) : world{world} {
        SetTexture(texturePath);
        transform.scale = 1;
    }

    void Actor::SetTexture(const std::string &texturePath) {
        texture = AssetsManager::Get().GetTexture(texturePath);
        textureRect = Rectangle(0, 0, texture->width, texture->height); // NOLINT(*-narrowing-conversions)
        size = Vector2(textureRect.width * transform.scale, textureRect.height * transform.scale);
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

        transform.rotation += deltaTime * 90;
        Update(deltaTime);
    }

    void Actor::Render() const {
        if (IsPendingDestruction()) return;
        const auto destRect = Rectangle(
            transform.position.x,
            transform.position.y,
            size.x,
            size.y);
        DrawTexturePro(*texture, textureRect, destRect,
                       Vector2{pivotOffset.x * transform.scale, pivotOffset.y * transform.scale}, transform.rotation,
                       WHITE);
    }

    Vector2 Actor::Position() const {
        return transform.position;
    }

    void Actor::SetPosition(const Vector2 &position) {
        transform.position = position;
    }

    void Actor::SetPositionOffset(const Vector2 &position) {
        transform.position.x += position.x;
        transform.position.y += position.y;
    }

    float Actor::Rotation() const {
        return transform.rotation;
    }

    void Actor::SetRotation(const float rotation) {
        transform.rotation = rotation;
    }

    void Actor::SetRotationOffset(const float rotation) {
        transform.rotation += rotation;
    }

    float Actor::Scale() const {
        return transform.scale;
    }

    void Actor::SetScale(const float scale) {
        transform.scale = scale;
        size = Vector2{textureRect.width * transform.scale, textureRect.height * transform.scale};
    }

    void Actor::SetScaleOffset(const float scale) {
        transform.scale += scale;
    }

    Vector2 Actor::GetForwardVector() const {
        return RotationToVector(transform.rotation);
    }

    Vector2 Actor::GetRightVector() const {
        return RotationToVector(transform.rotation + 90.f);
    }

    void Actor::SetPivotOffset(const Vector2 &pivot) {
        pivotOffset = pivot;
    }

    Vector2 Actor::GetTextureSize() const {
        return Vector2{textureRect.width, textureRect.height};
    }
}
