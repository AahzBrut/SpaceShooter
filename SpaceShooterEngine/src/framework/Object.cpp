#include "framework/Object.h"

namespace SpaceShooter {
    Object::Object() {
    }

    Object::~Object() {
    }

    void Object::Destroy() {
        isPendingDestruction = true;
    }

    bool Object::IsPendingDestruction() const {
        return isPendingDestruction;
    }
}
