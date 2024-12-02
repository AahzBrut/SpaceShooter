#include <format>
#include <string>

#include "raylib.h"
#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"


namespace SpaceShooter {
    Application::Application()
        : currentWorld(nullptr) {
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void Application::Run() {
        // NOLINT(*-convert-member-functions-to-static)
        InitWindow(800, 950, "Space shooter");
        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            UpdateInternal();
            RenderInternal();
        }
        CloseWindow();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void Application::RenderInternal() {// NOLINT(*-convert-member-functions-to-static)
        BeginDrawing();
        ClearBackground(SKYBLUE);

        const auto fpsString = std::format("FPS: {}", GetFPS());
        DrawText(fpsString.c_str(), 10, 10, 32, WHITE);

        LOG("FPS: %i", GetFPS());
        EndDrawing();
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
