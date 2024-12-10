#pragma once
#include <functional>

#include "Core.h"

namespace SpaceShooter {
    class Object;

    template<typename... Args>
    class Delegate {
    public:
        template<typename ClassName>
        void BindAction(const Weak<Object>& object, void (ClassName::*callback)(Args... args)) {
            auto callbackFunc = [object, callback](Args... args)->bool {
                if (!object.expired()) {
                    (static_cast<ClassName*>(object.lock().get())->*callback)(args...);
                    return true;
                }
                return false;
            };
            callbacks.push_back(callbackFunc);
        }

        void Emit(Args... args) {
            for (auto iter = callbacks.begin(); iter != callbacks.end();) {
                if ((*iter)(args...)) {
                    ++iter;
                } else {
                    iter = callbacks.erase(iter);
                }
            }
        }

    private:
        List<std::function<bool(Args ...)>> callbacks;
    };
}
