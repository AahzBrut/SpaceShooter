#include "widgets/Button.h"

#include "framework/AssetsManager.h"


namespace SpaceShooter {
    Button::Button(const std::string &caption, const std::string &texturePath)
        : text{caption},
          texture{AssetsManager::Get().GetTexture(texturePath)},
          font{AssetsManager::Get().GetFont("assets/SpaceShooterRedux/Bonus/kenvector_future.ttf")} {
        activeColor = defaultColor;
        size = Vector2{static_cast<float>(texture->width), static_cast<float>(texture->height)};
    }

    bool Button::HandleEvent() {
        const auto [mouseX, mouseY] = GetMousePosition();
        const auto [minX, minY] = GetPosition();
        const auto maxX = minX + size.x;
        const auto maxY = minY + size.y;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            if (mouseX >= minX && mouseX <= maxX && mouseY >= minY && mouseY <= maxY && isButtonDown) {
                ButtonClicked.Emit();
            }
            ButtonUp();
            return true;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (mouseX >= minX && mouseX <= maxX && mouseY >= minY && mouseY <= maxY) {
                ButtonDown();
                return true;
            }
        } else if (mouseX >= minX && mouseX <= maxX && mouseY >= minY && mouseY <= maxY && !isButtonDown) {
            ButtonHovered();
            return true;
        } else if (!isButtonDown) {
            activeColor = defaultColor;
        }

        return false;
    }

    void Button::OnDraw() {
        const auto textureWidth = static_cast<float>(texture->width);
        const auto textureHeight = static_cast<float>(texture->height);
        const auto [x, y] = GetPosition();
        const auto destRect = Rectangle(x, y, size.x, size.y);
        DrawTexturePro(*texture, {0, 0, textureWidth, textureHeight},
                       destRect,
                       {0, 0}, GetRotation(),
                       activeColor);

        const auto [textWidth, textHeight] = MeasureTextEx(*font, text.c_str(), fontSize, 2);
        const auto offsetX = x + (size.x - textWidth) * 0.5f;
        const auto offsetY = y + (size.y - textHeight) * 0.5f;
        DrawTextPro(*font, text.c_str(), {offsetX, offsetY}, {0, 0}, GetRotation(), fontSize, 2, textColor);
    }

    void Button::ButtonUp() {
        isButtonDown = false;
        activeColor = defaultColor;
    }

    void Button::ButtonDown() {
        isButtonDown = true;
        activeColor = pressedColor;
    }

    void Button::ButtonHovered() {
        activeColor = hoveredColor;
    }
}
