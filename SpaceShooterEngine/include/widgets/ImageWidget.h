#pragma once
#include "widgets/Widget.h"


namespace SpaceShooter {
    class ImageWidget final : public Widget {
    public:
        explicit ImageWidget(const std::string &texturePath);

        void SetTexture(const Shared<Texture> &texture) { this->texture = texture; }
        void SetSize(const Vector2 &newSize) { size = newSize; }
        Vector2 GetSize() const { return size; }

    private:
        Shared<Texture2D> texture{};
        Vector2 size;

        void OnDraw() override;
    };
}
