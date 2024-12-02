#pragma once

namespace SpaceShooter {
    class Object {
    public:
        Object();
        virtual ~Object();

        void Destroy();
        [[nodiscard]] bool IsPendingDestruction() const;

    private:
        bool isPendingDestruction = false;
    };
}
