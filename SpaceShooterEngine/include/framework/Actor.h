#pragma once

namespace SpaceShooter {
    class World;

    class Actor {
    public:
        explicit Actor(World *world);
        virtual ~Actor() = default;

        void InitializeInternal();
        void UpdateInternal(float deltaTime);

        virtual void Initialize() {
        }

        virtual void Update(float deltaTime) {
        }

    private:
        World *world;
        bool initialized = false;
    };
}
