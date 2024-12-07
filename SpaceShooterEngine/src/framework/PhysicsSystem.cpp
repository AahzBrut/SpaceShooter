#include "framework/PhysicsSystem.h"

#include "framework/MathUtility.h"

namespace SpaceShooter {
    Unique<PhysicsSystem> PhysicsSystem::instance{nullptr};

    PhysicsSystem::PhysicsSystem() {
        auto worldDefinition = b2DefaultWorldDef();
        worldDefinition.gravity = b2Vec2(0.0f, 0.0f);
        physicsWorld = b2CreateWorld(&worldDefinition);
        b2SetLengthUnitsPerMeter(100.0f);
    }

    PhysicsSystem &PhysicsSystem::Get() {
        if (!instance) {
            if (!instance) {
                instance = Unique<PhysicsSystem>{new PhysicsSystem()};
            }
        }
        return *instance;
    }

    void PhysicsSystem::Restart() {
        instance = Unique<PhysicsSystem>{new PhysicsSystem()};
    }

    void PhysicsSystem::Update(const float deltaTime) {
        ClearRemovedBodies();
        b2World_Step(physicsWorld, deltaTime, 4);
        const auto contactEvents = b2World_GetContactEvents(physicsWorld);
        for (auto index = 0; index < contactEvents.beginCount; index++) {
            const auto [shapeIdA, shapeIdB] = contactEvents.beginEvents[index];
            const auto firstBody = b2Shape_GetBody(shapeIdA);
            const auto secondBody = b2Shape_GetBody(shapeIdB);
            const auto firstActor = static_cast<Actor *>(b2Body_GetUserData(firstBody));
            const auto secondActor = static_cast<Actor *>(b2Body_GetUserData(secondBody));
            if (firstActor && !firstActor->IsPendingDestruction()) {
                firstActor->OnContactBegin(secondActor);
            }
            if (secondActor && !secondActor->IsPendingDestruction()) {
                secondActor->OnContactBegin(firstActor);
            }
        }
        for (auto index = 0; index < contactEvents.endCount; index++) {
            const auto [shapeIdA, shapeIdB] = contactEvents.endEvents[index];
            const auto firstBody = b2Shape_GetBody(shapeIdA);
            const auto secondBody = b2Shape_GetBody(shapeIdB);
            const auto firstActor = static_cast<Actor *>(b2Body_GetUserData(firstBody));
            const auto secondActor = static_cast<Actor *>(b2Body_GetUserData(secondBody));
            if (firstActor && !firstActor->IsPendingDestruction()) {
                firstActor->OnContactEnd(secondActor);
            }
            if (secondActor && !secondActor->IsPendingDestruction()) {
                secondActor->OnContactEnd(firstActor);
            }
        }
    }

    b2BodyId PhysicsSystem::AddListener(const Actor *listener, const CollisionLayers selfCollisionLayers, const CollisionLayers contactCollisionLayers) const {
        if (listener->IsPendingDestruction()) return b2_nullBodyId;
        const auto [actorX, actorY] = listener->Position();

        auto bodyDef = b2DefaultBodyDef();
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = b2Vec2{actorX, actorY};
        bodyDef.rotation = b2MakeRot(DegreesToRadians(listener->Rotation()));
        bodyDef.userData = const_cast<void *>(static_cast<void const *>(listener));
        bodyDef.enableSleep = false;
        const auto bodyId = b2CreateBody(physicsWorld, &bodyDef);

        const auto [actorWidth, actorHeight] = listener->GetSize();
        const auto polygonBox = b2MakeBox(actorWidth * 0.5f, actorHeight * 0.5f);
        auto shapeDef = b2DefaultShapeDef();
        shapeDef.density = 1.0f;
        shapeDef.friction = 0.3f;
        shapeDef.enableContactEvents = true;
        if (selfCollisionLayers != CollisionLayers::None && contactCollisionLayers != CollisionLayers::None) {
            shapeDef.filter.categoryBits = static_cast<uint32_t>(selfCollisionLayers);
            shapeDef.filter.maskBits = static_cast<uint32_t>(contactCollisionLayers);
        }
        b2CreatePolygonShape(bodyId, &shapeDef, &polygonBox);

        return bodyId;
    }

    void PhysicsSystem::RemoveListener(const b2BodyId bodyId) {
        bodiesToRemove.insert(bodyId);
    }

    void PhysicsSystem::ClearRemovedBodies() {
        for (const auto bodyId: bodiesToRemove) {
            b2DestroyBody(bodyId);
        }
        bodiesToRemove.clear();
    }
}
