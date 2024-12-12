#pragma once
#include <memory>

#include "Core.h"

namespace SpaceShooter {
    class Object : public std::enable_shared_from_this<Object> {
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual void Destroy() { isPendingDestruction = true; }
        [[nodiscard]] bool IsPendingDestruction() const { return isPendingDestruction; }
        Weak<Object> GetWeakRef() { return shared_from_this(); }
        Weak<const Object> GetWeakRef() const { return shared_from_this(); }

    private:
        bool isPendingDestruction = false;
    };
}
