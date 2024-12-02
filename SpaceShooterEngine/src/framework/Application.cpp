#include <format>
#include <string>

#include "raylib.h"
#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"


namespace SpaceShooter {
    Application::Application(const int width, const int height, const std::string& title)
        : currentWorld(nullptr)
    {
        InitWindow(width, height, title.c_str());
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void Application::Run() {
        // NOLINT(*-convert-member-functions-to-static)
        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            UpdateInternal();
            RenderInternal();
        }
        CloseWindow();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void Application::RenderInternal() {// NOLINT(*-convert-member-functions-to-static)
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
