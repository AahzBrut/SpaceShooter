#include "framework/Object.h"

namespace SpaceShooter {
    void Object::Destroy() {
        isPendingDestruction = true;
    }

    bool Object::IsPendingDestruction() const {
        return isPendingDestruction;
    }
}
