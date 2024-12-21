#pragma once
#include "framework/Delegate.h"
#include "widgets/Widget.h"


namespace SpaceShooter {
    class Button final : public Widget {
    public:
        explicit Button(const std::string &caption = "Button",
                        const std::string &texturePath = "assets/SpaceShooterRedux/PNG/UI/buttonBlue.png");

        void SetText(const std::string &newText) { text = newText; }
        void SetFontSize(const float newFontSize) { fontSize = newFontSize; }
        void SetSize(const Vector2& newSize) { size = newSize; }
        Vector2 GetSize() const { return size; }
        bool HandleEvent() override;

        Delegate<> ButtonClicked;

    private:
        std::string text;
        Shared<Texture> texture;
        Vector2 size{0,0};
        Shared<Font> font;
        float fontSize{16};
        Color textColor{WHITE};
        Color activeColor{WHITE};
        Color defaultColor{128, 128, 128, 255};
        Color pressedColor{64, 64, 64, 255};
        Color hoveredColor{192, 192, 192, 255};
        bool isButtonDown{false};

        void OnDraw() override;
        void ButtonUp();
        void ButtonDown();
        void ButtonHovered();
    };
}
