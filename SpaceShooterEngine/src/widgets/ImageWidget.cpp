#include "widgets/ImageWidget.h"

#include "framework/AssetsManager.h"


namespace SpaceShooter {
    ImageWidget::ImageWidget(const std::string &texturePath)
        : texture{AssetsManager::Get().GetTexture(texturePath)} {}

    void ImageWidget::OnDraw() {
        const auto destRect = Rectangle(
            GetPosition().x,
            GetPosition().y,
            static_cast<float>(texture->width),
            static_cast<float>(texture->height));
        DrawTexturePro(*texture, {0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height)},
                       destRect,
                       {0, 0}, GetRotation(),
                       WHITE);
    }
}
