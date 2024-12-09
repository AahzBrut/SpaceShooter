#include <format>
#include <string>

#include "raylib.h"
#include "framework/Application.h"

#include "framework/AssetsManager.h"
#include "framework/PhysicsSystem.h"
#include "framework/TimerManager.h"
#include "framework/World.h"


namespace SpaceShooter {
    Application::Application(const int width, const int height, const std::string &title)
        : currentWorld(nullptr) {
        windowSize = Vector2(static_cast<float>(width), static_cast<float>(height));
        InitWindow(width, height, title.c_str());
    }

    Application::~Application() {
        currentWorld.reset();
        AssetsManager::Get().CleanCycle();
    }

    void Application::Run() {
        SetTargetFPS(60);

        auto lastAssetsClearTime = GetTime();
        while (!WindowShouldClose()) {
            const auto deltaTime = GetFrameTime();
            UpdateInternal(deltaTime);
            RenderInternal();

            TimerManager::Get().UpdateTimers(deltaTime);
            PhysicsSystem::Get().Update(deltaTime);
            if (GetTime() - lastAssetsClearTime > cleanInterval) {
                lastAssetsClearTime = GetTime();
                AssetsManager::Get().CleanCycle();
                if (currentWorld) {
                    currentWorld->CleanCycle();
                }
            }
        }
        CloseWindow();
    }

    Vector2 Application::GetWindowSize() const {
        return windowSize;
    }

    void Application::RenderInternal() const {
        if (currentWorld) {
            currentWorld->Render();
        }
    }

    void Application::UpdateInternal(const float deltaTime) {
        Update(deltaTime);

        if (currentWorld) {
            currentWorld->InternalUpdate(deltaTime);
        }
    }

    void Application::Render() {}

    void Application::Update(float deltaTime) {}
}
