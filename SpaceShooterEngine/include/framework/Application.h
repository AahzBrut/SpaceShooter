#pragma once
#include "Core.h"
#include "World.h"

namespace SpaceShooter {
    class Application {
    public:
        Application(int width, int height, const std::string &title);
        virtual ~Application();

        void Run();

        template<typename WorldType>
        Weak<WorldType> LoadWorld();

    private:
        Shared<World> currentWorld;
        double cleanInterval{5};

        void UpdateInternal();
        void RenderInternal() const;
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
