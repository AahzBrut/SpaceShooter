#include "framework/World.h"

#include <format>

#include "audio/AudioManager.h"
#include "framework/Actor.h"
#include "framework/Application.h"
#include "framework/AssetsManager.h"
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
        AudioManager::Get().CleanCycle();
        AssetsManager::Get().CleanCycle();
    }

    void World::InternalInitialize() {
        if (!initialized) {
            initialized = true;
            Initialize();

            InitStages();
            StartStages();
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

        if (hud) {
            if (!hud->IsInitialized()) hud->Initialize();
            hud->Update(deltaTime);
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
    }

    void World::StartStages() {
        currentStage = stages.begin();
        if (currentStage != stages.end()) {
            currentStage->get()->StartStage();
            currentStage->get()->StageFinished.BindAction(GetWeakRef(), &World::NextStage);
        }
    }

    void World::NextStage() {
        currentStage = stages.erase(currentStage);
        if (currentStage != stages.end()) {
            currentStage->get()->StartStage();
            currentStage->get()->StageFinished.BindAction(GetWeakRef(), &World::NextStage);
        } else {
            AllStagesFinished();
        }
    }

    bool World::DispatchEvent() const {
        if (hud) {
            return hud->HandleEvent();
        }

        return false;
    }
}
