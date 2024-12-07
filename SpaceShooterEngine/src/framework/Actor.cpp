#include "raylib.h"
#include "framework/Actor.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"
#include "framework/MathUtility.h"
#include "framework/PhysicsSystem.h"
#include "framework/World.h"

namespace SpaceShooter {
    Actor::Actor(World *world, const std::string &texturePath, const CollisionLayers selfCollisionLayers,
                 const CollisionLayers contactCollisionLayers) : selfCollisionLayers{selfCollisionLayers}, contactCollisionLayers{contactCollisionLayers},
                                                                 world{world} {
        transform.scale = 1;
        SetTexture(texturePath);
    }

    void Actor::SetTexture(const std::string &texturePath) {
        texture = AssetsManager::Get().GetTexture(texturePath);
        textureRect = Rectangle(0, 0, texture->width, texture->height); // NOLINT(*-narrowing-conversions)
        size = Vector2(textureRect.width * transform.scale, textureRect.height * transform.scale);
    }

    Actor::~Actor() {
        SetPhysicsEnabled(false);
        LOG("Destroying Actor");
    }

    void Actor::InitializeInternal() {
        LOG("Initializing Actor");
        Initialize();
        initialized = true;
    }

    void Actor::UpdateInternal(const float deltaTime) {
        if (IsPendingDestruction()) return;

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
                       pivotOffset, transform.rotation,
                       WHITE);
    }

    Vector2 Actor::Position() const {
        return transform.position;
    }

    void Actor::SetPosition(const Vector2 &position) {
        transform.position = position;
        UpdatePhysicsBodyTransform();
    }

    void Actor::SetPositionOffset(const Vector2 &position) {
        SetPosition(Vector2(transform.position.x + position.x, transform.position.y + position.y));
    }

    float Actor::Rotation() const {
        return transform.rotation;
    }

    void Actor::SetRotation(const float rotation) {
        transform.rotation = rotation;
        UpdatePhysicsBodyTransform();
    }

    void Actor::SetRotationOffset(const float rotation) {
        SetRotation(transform.rotation + rotation);
    }

    float Actor::Scale() const {
        return transform.scale;
    }

    void Actor::SetScale(const float scale) {
        pivotOffset = Vector2(pivotOffset.x * (1 + scale - transform.scale),
                              pivotOffset.y * (1 + scale - transform.scale));
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

    void Actor::CenterPivotOffset() {
        pivotOffset = Vector2{textureRect.width * 0.5f * transform.scale, textureRect.height * 0.5f * transform.scale};
    }

    Vector2 Actor::GetTextureSize() const {
        return Vector2{textureRect.width, textureRect.height};
    }

    Vector2 Actor::GetWindowSize() const {
        return world->GetWindowSize();
    }

    Transform Actor::GetTransform() const {
        return transform;
    }

    bool Actor::IsOutOfWindowBounds() const {
        const auto [windowWidth, windowHeight] = GetWindowSize();
        return transform.position.x < -textureRect.width || transform.position.x > windowWidth + textureRect.width ||
               transform.position.y < -textureRect.height || transform.position.y > windowHeight + textureRect.height;
    }

    void Actor::SetPhysicsEnabled(const bool enablePhysics) {
        if (enablePhysics) {
            InitializePhysics();
        } else {
            UnInitializePhysics();
        }
    }

    void Actor::UpdatePhysicsBodyTransform() const {
        if (b2Body_IsValid(bodyId)) {
            const b2Vec2 position{transform.position.x + pivotOffset.x, transform.position.y + pivotOffset.y};
            const auto rotation = DegreesToRadians(transform.rotation);
            b2Body_SetTransform(bodyId, position, b2MakeRot(rotation));
        }
    }

    void Actor::OnContactBegin(Actor *actor) {
        if (const auto iterator = CollisionLayersNames.find(static_cast<int>(selfCollisionLayers)); iterator != CollisionLayersNames.end()) {
            LOG("OnContactBegin - %s", iterator->second.c_str());
        }
    }

    void Actor::OnContactEnd(Actor *actor) {
        if (const auto iterator = CollisionLayersNames.find(static_cast<int>(selfCollisionLayers)); iterator != CollisionLayersNames.end()) {
            LOG("OnContactEnd - %s", iterator->second.c_str());
        }
    }

    void Actor::Destroy() {
        UnInitializePhysics();
        Object::Destroy();
    }

    void Actor::InitializePhysics() {
        if (!b2Body_IsValid(bodyId)) {
            bodyId = PhysicsSystem::Get().AddListener(this, selfCollisionLayers, contactCollisionLayers);
        }
    }

    void Actor::UnInitializePhysics() {
        if (b2Body_IsValid(bodyId)) {
            PhysicsSystem::Get().RemoveListener(bodyId);
            bodyId = b2_nullBodyId;
        }
    }
}
