#pragma once

namespace SpaceShooter {
    class Application {
    public:
        Application() = default;
        virtual ~Application() = default;
        void Run();
    private:
        void UpdateInternal();
        void RenderInternal();
        virtual void Render();
        virtual void Update(float deltaTime);
    };
}
