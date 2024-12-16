#include "widgets/HUD.h"

namespace SpaceShooter {
    void HUD::Initialize() {
        if (!initialized) {
            initialized = true;
            OnInitialize();
        }
    }
}
