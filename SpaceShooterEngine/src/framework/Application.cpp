#include <format>
#include <string>

#include "raylib.h"
#include "framework/Application.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"
#include "framework/World.h"


namespace SpaceShooter {
    Application::Application(const int width, const int height, const std::string& title)
        : currentWorld(nullptr)
    {
        InitWindow(width, height, title.c_str());
    }

    Application::~Application() {
        currentWorld.reset();
        AssetsManager::Get().CleanCycle();
    }

    void Application::Run() {
        SetTargetFPS(60);

        auto lastAssetsClearTime =  GetTime();
        while (!WindowShouldClose()) {
            UpdateInternal();
            RenderInternal();
            if (GetTime() - lastAssetsClearTime > cleanInterval) {
                lastAssetsClearTime = GetTime();
                AssetsManager::Get().CleanCycle();
            }
        }
        CloseWindow();
    }

    void Application::RenderInternal() const {
        if (currentWorld) {
            currentWorld->Render();
        }
    }

    void Application::UpdateInternal() {
        const auto deltaTime = GetFrameTime();
        Update(deltaTime);

        if (currentWorld) {
            currentWorld->InternalUpdate(deltaTime);
        }
    }

    void Application::Render() {
    }

    void Application::Update(float deltaTime) {
    }
}
