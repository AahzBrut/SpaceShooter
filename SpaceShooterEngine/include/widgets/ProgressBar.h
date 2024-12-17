#pragma once
#include "widgets/Widget.h"


namespace SpaceShooter {
    class ProgressBar final : public Widget {
    public:
        explicit ProgressBar(const Vector2 &size = {200, 40},
                             const Color &frontColor = GREEN,
                             const Color &backColor = RED);

        void SetValue(const float value) { this->value = value; }

    private:
        Shared<Font> font;
        Vector2 size;
        float value{0.5f};
        Color frontColor, backColor;

        void OnDraw() override;
    };
}
