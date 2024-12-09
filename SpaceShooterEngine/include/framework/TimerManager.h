#pragma once
#include <functional>

#include "Core.h"
#include "Object.h"


namespace SpaceShooter {
    struct Timer {
        Timer(const Weak<Object>& object, const std::function<void()>& callback, float duration, bool repeat);
        void Tick(float deltaTime);

        [[nodiscard]] bool Expired() const {
            return expired || listener.first.expired() || listener.first.lock()->IsPendingDestruction();
        }

        void SetExpired() { expired = true; }

    private:
        std::pair<Weak<Object>, std::function<void()> > listener;
        float duration;
        bool repeat;
        float elapsedTime;
        bool expired;
    };

    class TimerManager {
    public:
        static TimerManager &Get();

        template<typename ClassName>
        unsigned int SetTimer(Weak<Object> object, void (ClassName::*callback)(), float duration, bool repeat = false) {
            timers.emplace(timerIndexCounter++, Timer(
                object,
                [=] { (static_cast<ClassName *>(object.lock().get())->*callback)(); },
                duration,
                repeat));
            return timerIndexCounter - 1;
        }

        void UpdateTimers(float deltaTime);
        void ClearTimer(unsigned int timerIndex);

    protected:
        TimerManager() = default;

    private:
        static Unique<TimerManager> instance;
        static unsigned int timerIndexCounter;
        Dictionary<unsigned int, Timer> timers;
    };
}
