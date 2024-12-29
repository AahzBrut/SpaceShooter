#include "audio/AudioManager.h"

#include "framework/Core.h"


namespace SpaceShooter {
    Unique<AudioManager> AudioManager::instance{nullptr};

    AudioManager & AudioManager::Get() {
        if (!instance) {
            instance = Unique<AudioManager>{new AudioManager()};
        }
        return *instance;
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void AudioManager::PlaySoundEffect(const Sound &sound) { // NOLINT(*-convert-member-functions-to-static)
        PlaySound(sound);
    }
}
