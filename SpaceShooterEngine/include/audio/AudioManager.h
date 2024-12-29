#pragma once
#include <raylib.h>

#include "framework/Core.h"


namespace SpaceShooter {
    class AudioManager {
    public:
        static AudioManager &Get();

        void PlaySoundEffect(const Shared<Sound> &sound);
        void Update();

    protected:
        AudioManager() = default;

    private:
        static Unique<AudioManager> instance;
        List<Pair<Weak<Sound>, Sound>> sounds{};
    };
}
