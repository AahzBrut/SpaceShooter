#include "framework/Core.h"
#include "framework/World.h"

#include <format>

#include "framework/Actor.h"
#include "framework/Application.h"
#include "gameplay/GameStage.h"


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
            NextStage();
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

        if (currentStageIndex >= 0 && currentStageIndex < stages.size()) {
            stages[currentStageIndex]->Update(deltaTime);
        }

        Update(deltaTime);
    }

    void World::Render() const {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        for (const auto &actor: childActors) {
            actor->Render();
        }

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

        for (auto iterator = stages.begin(); iterator < stages.end();) {
            if (iterator->get()->IsFinished()) {
                iterator = stages.erase(iterator);
            } else {
                ++iterator;
            }
        }
    }

    void World::AddStage(const Shared<GameStage> &newStage) {
        stages.push_back(newStage);
    }

    void World::AllStatesFinished() {}

    void World::NextStage() {
        ++currentStageIndex;
        if (currentStageIndex >= 0 && currentStageIndex < stages.size()) {
            stages[currentStageIndex]->StageFinished.BindAction(GetWeakRef(), &World::NextStage);
            stages[currentStageIndex]->Initialize();
        } else {
            AllStatesFinished();
        }
    }
}
