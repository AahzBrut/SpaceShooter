#pragma once
#include <raylib.h>

#include "framework/Core.h"


namespace SpaceShooter {
    class AudioManager {
    public:
        static AudioManager &Get();

        void PlaySoundEffect(const Sound &sound);

    protected:
        AudioManager() = default;

    private:
        static Unique<AudioManager> instance;
    };
}
