#pragma once
#include "framework/Object.h"
#include "framework/Transform.h"

namespace SpaceShooter {
    class Widget : public Object {
    public:
        void Draw() { if (IsVisible()) OnDraw(); }
        virtual bool HandleEvent() { return false; }

        void SetPosition(const Vector2 &newPosition) {
            transform.position = newPosition;
            OnPositionChanged(newPosition);
        }

        Vector2 GetPosition() const { return transform.position; }

        void SetRotation(const float newRotation) {
            transform.rotation = newRotation;
            OnRotationChanged(newRotation);
        }

        float GetRotation() const { return transform.rotation; }

        void SetScale(const float newScale) { transform.scale = newScale; }
        float GetScale() const { return transform.scale; }

        void SetVisible(const bool visible) { isVisible = visible; }
        bool IsVisible() const { return isVisible; }

    protected:
        Widget() = default;

    private:
        Transform transform{};
        bool isVisible{true};

        virtual void OnDraw() = 0;
        virtual void OnPositionChanged(const Vector2 &newPosition){}
        virtual void OnRotationChanged(float newRotation){}
    };
}
