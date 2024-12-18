#pragma once
#include "widgets/Widget.h"


namespace SpaceShooter {
    class ImageWidget final : public Widget {
    public:
        explicit ImageWidget(const std::string &texturePath);

        void SetTexture(const Shared<Texture> &texture) { this->texture = texture; }

    private:
        Shared<Texture2D> texture{};

        void OnDraw() override;
    };
}
