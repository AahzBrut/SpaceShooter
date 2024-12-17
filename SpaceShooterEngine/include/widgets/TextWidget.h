#pragma once
#include "Widget.h"


namespace SpaceShooter {
    class TextWidget : public Widget {
    public:
        explicit TextWidget(const std::string &text,
                            const std::string &fontPath = "assets/SpaceShooterRedux/Bonus/kenvector_future.ttf",
                            float fontSize = 16);

        void SetText(const std::string &text);
        void SetFontSize(float size);

    private:
        std::string text;
        Shared<Font> font;
        float fontSize;

        void OnDraw() override;
    };
}
