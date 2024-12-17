#include "widgets/ProgressBar.h"

#include <format>

#include "framework/AssetsManager.h"


namespace SpaceShooter {
    ProgressBar::ProgressBar(const Vector2 &size, const Color &frontColor, const Color &backColor)
        : font{AssetsManager::Get().GetFont("assets/SpaceShooterRedux/Bonus/kenvector_future.ttf")},
          size{size},
          frontColor{frontColor},
          backColor{backColor} {}

    void ProgressBar::OnDraw() {
        const auto text = std::format("{} %", static_cast<int>(value * 100));

        const auto [textWidth, textHeight] = MeasureTextEx(*font, text.c_str(), 32, 2);
        const auto [x, y] = GetPosition();
        const auto offsetX = x + (size.x - textWidth) * 0.5f;
        const auto offsetY = y + (size.y - textHeight) * 0.5f;

        DrawRectanglePro({x, y, size.x, size.y}, {0, 0}, GetRotation(), backColor);
        DrawRectanglePro({x, y, size.x * value, size.y}, {0, 0}, GetRotation(), frontColor);
        DrawTextPro(*font, text.c_str(), {offsetX, offsetY}, {0, 0}, GetRotation(), 32, 2, BLACK);
    }
}
