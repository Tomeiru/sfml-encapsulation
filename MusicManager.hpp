#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "RuntimeException.hpp"
#include "Music.hpp"

namespace SFML {
    class MusicManager {
    public:
        void registerMusic(const std::string &id, const std::string &filename, bool is_looping = true, Music::Status status = Music::Stopped) {
            if (musics.find(id) != musics.end())
                throw RuntimeException("MusicManager::registerMusic", "A music with this ID has already been registered");
            std::shared_ptr<Music> music = std::make_shared<Music>(filename, _volume, is_looping, status);
            musics.emplace(id, music);
        }

        std::shared_ptr<Music> getMusic(const std::string &id) {
            if (musics.find(id) == musics.end())
                throw RuntimeException("MusicManager::getMusic", "The ID provided doesn't match with any music previously registered");
            return musics.at(id);
        }

        void setMusicsVolume(float volume) {
            _volume = volume;
            for (const auto &[_, music] : musics) {
                music->setVolume(volume);
            }
        }

        bool isEnabled() const {
            return (is_enabled);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Music>> musics;
        bool is_enabled = true;
        float _volume = 100.0;
    };
}