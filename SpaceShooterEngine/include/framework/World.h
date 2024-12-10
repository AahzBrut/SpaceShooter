#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Application;
    class GameStage;

    // ReSharper disable once CppClassCanBeFinal
    class World : public Object {
    public:
        explicit World(Application *application);
        ~World() override;

        void InternalInitialize();
        void InternalUpdate(float deltaTime);

        template<typename ActorType, typename... Args>
        Weak<ActorType> SpawnActor(Args... args);

        void Render() const;
        [[nodiscard]] Vector2 GetWindowSize() const;
        void CleanCycle();
        void AddStage(const Shared<GameStage> &newStage);

    private:
        Application *application;
        bool initialized;
        List<Shared<Actor> > childActors{};
        List<Shared<Actor> > pendingActors{};
        List<Shared<GameStage> > stages{};
        List<Shared<GameStage> >::iterator currentStage{stages.end()};

        virtual void InitStages() {}
        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}
        virtual void AllStagesFinished();

        void StartStages();
        void NextStage();
    };

    template<typename ActorType, typename... Args>
    Weak<ActorType> World::SpawnActor(Args... args) {
        Shared<ActorType> actor{new ActorType(this, args...)};
        pendingActors.push_back(actor);
        return actor;
    }
}
