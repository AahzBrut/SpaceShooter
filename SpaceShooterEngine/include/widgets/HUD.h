#pragma once
#include "framework/Object.h"


namespace SpaceShooter {
    class HUD : public Object {
    public:
        virtual void Draw() = 0;
        virtual bool HandleEvent() { return false; }
        virtual void Update(float deltaTime) {}

        void Initialize();
        bool IsInitialized() const { return initialized; }

    protected:
        HUD() = default;

    private:
        bool initialized{false};

        virtual void OnInitialize(){}
    };
}
