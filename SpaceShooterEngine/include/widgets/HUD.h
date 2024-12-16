#pragma once
#include "framework/Object.h"


namespace SpaceShooter {
    class HUD : public Object {
    public:
        virtual void Draw() = 0;
        virtual bool HandleEvent() = 0;

        void Initialize();
        bool IsInitialized() const { return initialized; }

    protected:
        HUD() = default;

    private:
        bool initialized{false};

        virtual void OnInitialize() = 0;
    };
}
