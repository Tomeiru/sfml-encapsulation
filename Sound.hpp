#pragma once

#include <memory>
#include <SFML/Audio/Sound.hpp>
#include "SoundBuffer.hpp"

namespace SFML {
    class Sound {
    public:
        enum Status {
            Stopped = sf::SoundSource::Stopped,
            Paused = sf::SoundSource::Paused,
            Playing = sf::SoundSource::Playing
        };
        Sound(const std::shared_ptr<SoundBuffer> &sound_buffer, float volume = 100, bool is_looping = true, Status status = Stopped) : sound(sound_buffer->getSoundBuffer()), _is_looping(is_looping), status(status) {
            if (volume > 100)
                volume = 100;
            if (volume < 0)
                volume = 0;
            _volume = volume;
            sound.setVolume(_volume);
            sound.setLoop(is_looping);
        };
        const sf::Sound &getSound() const {
            return sound;
        }
        void play() {
            sound.play();
            status = Playing;
        }
        void pause() {
            sound.pause();
            status = Paused;
        }
        void stop() {
            sound.stop();
            status = Stopped;
        }
        void setVolume(float volume) {
            if (volume > 100)
                volume = 100;
            if (volume < 0)
                volume = 0;
            sound.setVolume(volume);
            _volume = volume;
        }
        void setLoop(bool is_looping) {
            sound.setLoop(is_looping);
            _is_looping = is_looping;
        }
        const Status &getStatus() const {
            return (status);
        };
        void updateStatus() {
            status = (Status)sound.getStatus();
        }
    private:
        float _volume;
        bool _is_looping;
        sf::Sound sound;
        Status status;

    };
}
