#pragma once
#include "Widget.h"


namespace SpaceShooter {
    class TextWidget final : public Widget {
    public:
        explicit TextWidget(const std::string &text,
                            const std::string &fontPath = "assets/SpaceShooterRedux/Bonus/kenvector_future.ttf",
                            float fontSize = 16,
                            float spacing = 2,
                            const Color &color = WHITE);

        void SetText(const std::string &newText) { text = newText; }
        void SetFontSize(const float newSize) { fontSize = newSize; }
        Vector2 GetBounds() const;
        void SetColor(const Color &newColor) { color = newColor; }
        void SetSpacing(const float newSpacing) { spacing = newSpacing; }

    private:
        std::string text;
        Shared<Font> font;
        float fontSize;
        float spacing;
        Color color;

        void OnDraw() override;
    };
}
