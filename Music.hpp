#pragma once

#include <string>
#include <SFML/Audio/Music.hpp>
#include "RuntimeException.hpp"

namespace SFML {
    class Music {
    public:
        enum Status {
            Stopped = sf::Music::Stopped,
            Paused = sf::Music::Paused,
            Playing = sf::Music::Playing
        };
        Music(const std::string &filename, float volume = 100, bool is_looping = true, Status status = Stopped) : music(), _is_looping(is_looping), status(status) {
            if (!music.openFromFile(filename))
                throw RuntimeException("Music::ctor", "music.openFromFile failed, filename must be invalid");
            if (volume > 100)
                volume = 100;
            if (volume < 0)
                volume = 0;
            _volume = volume;
            music.setVolume(_volume);
            music.setLoop(is_looping);
        }
        const sf::Music &getMusic() const {
            return music;
        }
        void play() {
            music.play();
            status = Playing;
        }
        void pause() {
            music.pause();
            status = Paused;
        }
        void stop() {
            music.stop();
            status = Stopped;
        }
        void setVolume(float volume) {
            if (volume > 100)
                volume = 100;
            if (volume < 0)
                volume = 0;
            music.setVolume(volume);
            _volume = volume;
        }
        void setLoop(bool is_looping) {
            music.setLoop(is_looping);
            _is_looping = is_looping;
        }
        const Status &getStatus() const {
            return (status);
        };
        void updateStatus() {
            status = (Status)music.getStatus();
        }
    private:
        float _volume;
        bool _is_looping;
        sf::Music music;
        Status status;
    };
}