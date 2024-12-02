#pragma once
#include "Object.h"

namespace SpaceShooter {
    class World;

    // ReSharper disable once CppClassCanBeFinal
    class Actor: public Object {
    public:
        explicit Actor(World *world);
        ~Actor() override;

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
