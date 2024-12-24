#pragma once
#include "Actor.h"


namespace SpaceShooter {
    class ScrollingBackground final : public Actor {
    public:
        explicit ScrollingBackground(World *world, const std::string &texturePath = "assets/SpaceShooterRedux/Backgrounds/black.png", float scrollSpeed = -50);
        void Render() const override;
        void Update(float deltaTime) override;

    private:
        float scrollSpeed;
        float currentOffset{0};
    };
}
