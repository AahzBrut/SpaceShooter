#pragma once
#include "Core.h"
#include "World.h"

namespace SpaceShooter {
    class Application {
    public:
        Application();
        virtual ~Application() = default;
        void Run();

        template<typename WorldType>
        Weak<WorldType> LoadWorld();

    private:
        Shared<World> currentWorld;
        void UpdateInternal();
        void RenderInternal();
        virtual void Render();
        virtual void Update(float deltaTime);
    };

    template<typename WorldType>
    Weak<WorldType> Application::LoadWorld() {
        Shared<WorldType> newWorld{new WorldType{this}};
        currentWorld = newWorld;
        currentWorld->InternalInitialize();
        return newWorld;
    }
}
