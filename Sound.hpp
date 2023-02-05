#pragma once

#include "SoundBuffer.hpp"
#include <SFML/Audio/Sound.hpp>
#include <memory>

namespace SFML {
/**
 * @brief A encapsulation of sf::Sound
 */
class Sound {
public:
    /**
     * @brief Sound status enumeration
     */
    enum Status {
        Stopped = sf::SoundSource::Stopped,
        Paused = sf::SoundSource::Paused,
        Playing = sf::SoundSource::Playing
    };
    /**
     * @brief Construct a new Sound object
     *
     * @param sound_buffer The sound buffer
     * @param volume The volume of the sound
     * @param is_looping If the sound is looping
     * @param status The status of the sound
     */
    Sound(const std::shared_ptr<SoundBuffer>& sound_buffer, float volume = 100, bool is_looping = true, Status status = Stopped)
        : sound(sound_buffer->getSoundBuffer())
        , _is_looping(is_looping)
        , status(status)
    {
        if (volume > 100)
            volume = 100;
        if (volume < 0)
            volume = 0;
        _volume = volume;
        sound.setVolume(_volume);
        sound.setLoop(is_looping);
    };
    /**
     * @brief Get the Sound object
     *
     * @return const sf::Sound& The sound
     */
    const sf::Sound& getSound() const
    {
        return sound;
    }
    /**
     * @brief Play the sound
     */
    void play()
    {
        sound.play();
        status = Playing;
    }
    /**
     * @brief Pause the sound
     */
    void pause()
    {
        sound.pause();
        status = Paused;
    }
    /**
     * @brief Stop the sound
     */
    void stop()
    {
        sound.stop();
        status = Stopped;
    }
    /**
     * @brief Set the volume of the sound
     */
    void setVolume(float volume)
    {
        if (volume > 100)
            volume = 100;
        if (volume < 0)
            volume = 0;
        sound.setVolume(volume);
        _volume = volume;
    }
    /**
     * @brief Set if the sound is looping
     */
    void setLoop(bool is_looping)
    {
        sound.setLoop(is_looping);
        _is_looping = is_looping;
    }
    /**
     * @brief Get the status of the sound
     *
     * @return const Status& The status of the sound
     */
    const Status& getStatus() const
    {
        return (status);
    };
    /**
     * @brief Update the status of the sound
     */
    void updateStatus()
    {
        status = (Status)sound.getStatus();
    }

private:
    float _volume;
    bool _is_looping;
    sf::Sound sound;
    Status status;
};
}
