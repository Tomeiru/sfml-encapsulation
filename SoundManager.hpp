#pragma once


#include <memory>
#include <unordered_map>
#include "RuntimeException.hpp"
#include "Sound.hpp"

namespace SFML {
    class SoundManager {
    public:
        void registerSound(const std::string &id, const std::shared_ptr<SoundBuffer> &sound_buffer, bool is_looping = true, Sound::Status status = Sound::Stopped) {
            if (sounds.find(id) != sounds.end())
                throw RuntimeException("SoundManager::registerSound", "A sound with this ID has already been registered");
            std::shared_ptr<Sound> sound = std::make_shared<Sound>(sound_buffer, _volume, is_looping, status);
            sounds.emplace(id, sound);
        }

        std::shared_ptr<Sound> getSound(const std::string &id) {
            if (sounds.find(id) == sounds.end())
                throw RuntimeException("SoundManager::getSound", "The ID provided doesn't match with any sound previously registered");
            return sounds.at(id);
        }

        void setSoundsVolume(float volume) {
            _volume = volume;
            for (const auto &[_, sound] : sounds) {
                sound->setVolume(volume);
            }
        }

        bool isEnabled() const {
            return (is_enabled);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Sound>> sounds;
        bool is_enabled = true;
        float _volume = 100.0;
    };
}
