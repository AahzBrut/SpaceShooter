#include "framework/TimerManager.h"

namespace SpaceShooter {
    Unique<TimerManager> TimerManager::instance{nullptr};

    Timer::Timer(const Weak<Object> &object,
                 const std::function<void()> &callback,
                 const float duration,
                 const bool repeat)
        : listener{object, callback},
          duration{duration},
          repeat{repeat},
          elapsedTime{0},
          expired{false} {}

    void Timer::Tick(const float deltaTime) {
        if (Expired()) return;
        elapsedTime += deltaTime;
        if (elapsedTime >= duration) {
            listener.second();
            if (repeat) {
                elapsedTime = 0.f;
            } else {
                SetExpired();
            }
        }
    }

    TimerManager &TimerManager::Get() {
        if (!instance) {
            instance = std::move(Unique<TimerManager>{new TimerManager()});
        }
        return *instance;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void TimerManager::UpdateTimers(const float deltaTime) {
        for (auto &timer: timers) {
            timer.Tick(deltaTime);
        }
    }
}
