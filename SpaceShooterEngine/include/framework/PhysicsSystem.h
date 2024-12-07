#pragma once
#include "Core.h"
#include "Actor.h"


namespace SpaceShooter {
    class PhysicsSystem {
    public:
        static PhysicsSystem &Get();
        static void Restart();

        void Update(float deltaTime);
        b2BodyId AddListener(const Actor* listener) const;
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
