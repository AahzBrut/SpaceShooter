#pragma once
#include <memory>

#include "Core.h"

namespace SpaceShooter {
    class Object : public std::enable_shared_from_this<Object> {
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual void Destroy();
        [[nodiscard]] bool IsPendingDestruction() const;
        Weak<Object> GetWeakPtr() { return shared_from_this(); }
        Weak<const Object> GetWeakPtr() const { return shared_from_this(); }

    private:
        bool isPendingDestruction = false;
    };
}
