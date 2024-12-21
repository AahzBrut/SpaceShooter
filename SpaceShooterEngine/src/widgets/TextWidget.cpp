#include "widgets/TextWidget.h"

#include "framework/AssetsManager.h"

namespace SpaceShooter {
    TextWidget::TextWidget(const std::string &text, const std::string &fontPath, const float fontSize, const float spacing,
                           const Color &color)
        : text{text},
          font{AssetsManager::Get().GetFont(fontPath)},
          fontSize{fontSize},
          spacing{spacing},
          color{color} {}

    Vector2 TextWidget::GetBounds() const {
        return MeasureTextEx(*font, text.c_str(), fontSize, spacing);
    }

    void TextWidget::OnDraw() {
        DrawTextPro(*font.get(), text.c_str(), GetPosition(), {0, 0}, GetRotation(), fontSize, spacing, color);
    }
}
