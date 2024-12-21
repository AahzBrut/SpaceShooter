#pragma once
#include "Core.h"
#include "World.h"

namespace SpaceShooter {
    class Application {
    public:
        Application(int width, int height, const std::string &title);
        virtual ~Application();

        bool DispatchEvent() const;
        void Run();
        void Quit() { quitRequested = true; }

        template<typename WorldType>
        Weak<WorldType> LoadWorld();
        [[nodiscard]] Vector2 GetWindowSize() const;

    private:
        Shared<World> currentWorld;
        Shared<World> pendingWorld;
        double cleanInterval{2.5f};
        Vector2 windowSize{};
        bool quitRequested{false};

        void UpdateInternal(float deltaTime);
        void RenderInternal() const;
        virtual void Render() {}
        virtual void Update(float deltaTime) {}
    };

    template<typename WorldType>
    Weak<WorldType> Application::LoadWorld() {
        Shared<WorldType> newWorld{new WorldType{this}};
        pendingWorld = newWorld;
        return newWorld;
    }
}
