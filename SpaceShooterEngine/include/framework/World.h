#pragma once
#include "framework/Actor.h"

namespace SpaceShooter {
    class Application;

    // ReSharper disable once CppClassCanBeFinal
    class World {
    public:
        explicit World(Application *application);
        virtual ~World() = default;

        void InternalInitialize();
        void InternalUpdate(float deltaTime);

        template<typename ActorType>
        Weak<ActorType> SpawnActor();

    private:
        Application *application;
        bool initialized;
        List<Shared<Actor> > childActors{};
        List<Shared<Actor> > pendingActors{};

        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}
    };

    template<typename ActorType>
    Weak<ActorType> World::SpawnActor() {
        Shared<ActorType> actor{new ActorType{this}};
        pendingActors.push_back(actor);
        return actor;
    }
}
