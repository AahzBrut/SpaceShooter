#pragma once
#include "Core.h"

namespace SpaceShooter {
    class Actor;

    class PhysicsSystem {
    public:
        static PhysicsSystem &Get();
        static void Restart();

        void Update(float deltaTime);
        b2BodyId AddListener(const Actor* listener, CollisionLayers selfCollisionLayers, CollisionLayers contactCollisionLayers) const;
        void RemoveListener(b2BodyId bodyId);
        void ClearRemovedBodies();

    protected:
        PhysicsSystem();

    private:
        static Unique<PhysicsSystem> instance;
        b2WorldId physicsWorld{};
        Set<b2BodyId> bodiesToRemove{};
    };
}
