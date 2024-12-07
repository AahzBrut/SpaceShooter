#pragma once

namespace SpaceShooter {
    class Object {
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual void Destroy();
        [[nodiscard]] bool IsPendingDestruction() const;

    private:
        bool isPendingDestruction = false;
    };
}
