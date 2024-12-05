#include "framework/PhysicsSystem.h"

#include "framework/MathUtility.h"

namespace SpaceShooter {
    Unique<PhysicsSystem> PhysicsSystem::instance{nullptr};

    PhysicsSystem::PhysicsSystem() {
        auto worldDefinition = b2DefaultWorldDef();
        worldDefinition.gravity = b2Vec2(0.0f, 0.0f);
        physicsWorld = b2CreateWorld(&worldDefinition);
    }

    PhysicsSystem& PhysicsSystem::Get() {
        if (!instance) {
            if (!instance) {
                instance = Unique<PhysicsSystem>{new PhysicsSystem()};
            }
        }
            return *instance;
    }

    void PhysicsSystem::Update(const float deltaTime) const {
        b2World_Step(physicsWorld, deltaTime, 4);
    }

    b2BodyId PhysicsSystem::AddListener(const Actor* listener) const {
        if (listener->IsPendingDestruction()) return b2_nullBodyId;
        const auto [actorX, actorY] = listener->Position();

        auto bodyDef = b2DefaultBodyDef();
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = b2Vec2{actorX * scale, actorY * scale};
        bodyDef.rotation = b2MakeRot(DegreesToRadians(listener->Rotation()));
        bodyDef.userData = &listener;
        const auto bodyId = b2CreateBody(physicsWorld, &bodyDef);

        const auto [actorWidth, actorHeight] = listener->GetSize();
        const auto polygonBox = b2MakeBox(actorWidth * 0.5f * scale, actorHeight * 0.5f * scale);
        auto shapeDef = b2DefaultShapeDef();
        shapeDef.density = 1.0f;
        shapeDef.friction = 0.3f;
        shapeDef.isSensor = true;
        b2CreatePolygonShape(bodyId, &shapeDef, &polygonBox);

        return bodyId;
    }
}
