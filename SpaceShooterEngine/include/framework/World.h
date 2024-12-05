#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Application;

    // ReSharper disable once CppClassCanBeFinal
    class World {
    public:
        explicit World(Application *application);
        virtual ~World();

        void InternalInitialize();
        void InternalUpdate(float deltaTime);

        template<typename ActorType, typename ... Args>
        Weak<ActorType> SpawnActor(Args ...args);
        void Render() const;

        Vector2 GetWindowSize() const;

    private:
        Application *application;
        bool initialized;
        List<Shared<Actor> > childActors{};
        List<Shared<Actor> > pendingActors{};

        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}
    };

    template<typename ActorType, typename ... Args>
    Weak<ActorType> World::SpawnActor(Args ...args) {
        Shared<ActorType> actor{new ActorType(this, args...)};
        pendingActors.push_back(actor);
        return actor;
    }
}
