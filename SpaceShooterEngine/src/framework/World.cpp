#include "framework/World.h"

#include <format>

#include "framework/Actor.h"
#include "framework/Application.h"
#include "framework/Core.h"
#include "gameplay/GameStage.h"
#include "widgets/HUD.h"


namespace SpaceShooter {
    World::World(Application *application)
        : application(application),
          initialized(false) {}

    World::~World() {
        for (auto iterator = pendingActors.begin(); iterator < pendingActors.end();) {
            iterator = pendingActors.erase(iterator);
        }
        for (auto iterator = childActors.begin(); iterator < childActors.end();) {
            iterator = childActors.erase(iterator);
        }
    }

    void World::InternalInitialize() {
        if (!initialized) {
            initialized = true;
            Initialize();

            InitStages();
            StartStages();
            LOG("Initializing world\n");
        }
    }

    void World::InternalUpdate(const float deltaTime) {
        for (const auto &actor: pendingActors) {
            childActors.push_back(actor);
            actor->InitializeInternal();
        }
        pendingActors.clear();

        for (auto iterator = childActors.begin(); iterator < childActors.end();) {
            iterator->get()->UpdateInternal(deltaTime);
            ++iterator;
        }

         if (currentStage != stages.end()) {
             currentStage->get()->Update(deltaTime);
         }

        Update(deltaTime);

        if (hud && hud->IsInitialized()) {
            hud->Initialize();
        }
    }

    void World::RenderHUD() const {
        if (hud) hud->Draw();
    }

    void World::Render() const {
        BeginDrawing();
        ClearBackground(BLACK);

        for (const auto &actor: childActors) {
            actor->Render();
        }

        RenderHUD();

        const auto fpsString = std::format("FPS: {}", GetFPS());
        DrawText(fpsString.c_str(), 10, 10, 32, WHITE);

        EndDrawing();
    }

    Vector2 World::GetWindowSize() const {
        return application->GetWindowSize();
    }

    void World::CleanCycle() {
        for (auto iterator = childActors.begin(); iterator < childActors.end();) {
            if (const auto actor = iterator->get(); actor->IsPendingDestruction()) {
                iterator = childActors.erase(iterator);
            } else {
                ++iterator;
            }
        }
    }

    void World::AddStage(const Shared<GameStage> &newStage) {
        stages.push_back(newStage);
    }

    void World::AllStagesFinished() {
        LOG("All Stages Finished");
    }

    void World::StartStages() {
        currentStage = stages.begin();
        if (currentStage != stages.end()) {
            currentStage->get()->StartStage();
            currentStage->get()->StageFinished.BindAction(GetWeakRef(), &World::NextStage);
        }
    }

    void World::NextStage() {
        LOG("Next stage\n");
        currentStage = stages.erase(currentStage);
        if (currentStage != stages.end()) {
            currentStage->get()->StartStage();
            currentStage->get()->StageFinished.BindAction(GetWeakRef(), &World::NextStage);
        } else {
            AllStagesFinished();
        }
    }

    bool World::DispatchEvent() {
        if (hud) {
            return hud->HandleEvent();
        }

        return false;
    }
}
