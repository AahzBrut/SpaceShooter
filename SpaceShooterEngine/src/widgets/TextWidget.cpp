#include "widgets/TextWidget.h"

#include "framework/AssetsManager.h"

namespace SpaceShooter {
    TextWidget::TextWidget(const std::string &text, const std::string &fontPath, const float fontSize)
        : text{text},
          font{AssetsManager::Get().GetFont(fontPath)},
          fontSize{fontSize} {}

    void TextWidget::SetText(const std::string &text) {
        this->text = text;
    }

    void TextWidget::SetFontSize(const float size) {
        this->fontSize = size;
    }

    void TextWidget::OnDraw() {
        DrawTextPro(*font.get(), text.c_str(), GetPosition(), {0,0}, GetRotation(), fontSize, 2, WHITE);
    }
}
