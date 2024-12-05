#pragma once
#include "Core.h"
#include "Actor.h"


namespace SpaceShooter {
    class PhysicsSystem {
    public:
        static PhysicsSystem &Get();

        void Update(float deltaTime) const;
        b2BodyId AddListener(const Actor* listener) const;
        static void RemoveListener(b2BodyId bodyId);
        [[nodiscard]] float GetScale() const { return scale; }

    protected:
        PhysicsSystem();

    private:
        static Unique<PhysicsSystem> instance;
        b2WorldId physicsWorld{};
        float scale{0.01f};
    };
}
