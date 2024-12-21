#include "widgets/ImageWidget.h"

#include "framework/AssetsManager.h"


namespace SpaceShooter {
    ImageWidget::ImageWidget(const std::string &texturePath)
        : texture{AssetsManager::Get().GetTexture(texturePath)},
          size{static_cast<float>(texture->width), static_cast<float>(texture->height)} {}

    void ImageWidget::OnDraw() {
        const auto destRect = Rectangle(
            GetPosition().x,
            GetPosition().y,
            size.x,
            size.y);
        DrawTexturePro(*texture, {0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height)},
                       destRect,
                       {0, 0}, GetRotation(),
                       WHITE);
    }
}
