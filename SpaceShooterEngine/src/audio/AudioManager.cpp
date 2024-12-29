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

    void AudioManager::PlaySoundEffect(const Shared<Sound> &sound) {
        sounds.emplace_back(sound, LoadSoundAlias(*sound));
        PlaySound(sounds.back().second);
    }

    void AudioManager::Update() {
        for (auto iterator = sounds.begin(); iterator != sounds.end();) {
            if (!IsSoundPlaying(iterator->second)) {
                UnloadSoundAlias(iterator->second);
                iterator = sounds.erase(iterator);
            } else {
                ++iterator;
            }
        }
    }
}
