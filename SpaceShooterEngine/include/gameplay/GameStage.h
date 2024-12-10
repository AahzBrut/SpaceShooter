#pragma once
#include "framework/Delegate.h"
#include "framework/Object.h"


namespace SpaceShooter {
    class World;

    class GameStage : Object {
    public:
        explicit GameStage(World *world);

        const World *GetWorld() const { return world; }
        World *GetWorld() { return world; }

        Delegate<> StageFinished;

        virtual void Initialize();
        virtual void Update(float deltaTime);
        void FinishStage();
        bool IsFinished() const { return stageFinished; }

    private:
        World *world;
        bool stageFinished;

        virtual void OnStageFinished();
    };
}
