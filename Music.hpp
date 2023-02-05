#pragma once

#include "RuntimeException.hpp"
#include <SFML/Audio/Music.hpp>
#include <string>

namespace SFML {
/**
 * @brief A encapsulation of sf::Music
 */
class Music {
public:
    /**
     * @brief Music status enumeration
     */
    enum Status {
        Stopped = sf::Music::Stopped,
        Paused = sf::Music::Paused,
        Playing = sf::Music::Playing
    };
    /**
     * @brief Construct a new Music object
     *
     * @param filename The path to the music file
     * @param volume The volume of the music
     * @param is_looping If the music is looping
     * @param status The status of the music
     */
    Music(const std::string& filename, float volume = 100, bool is_looping = true, Status status = Stopped)
        : music()
        , _is_looping(is_looping)
        , status(status)
    {
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
    /**
     * @brief Get the Music object
     *
     * @return const sf::Music& The music
     */
    const sf::Music& getMusic() const
    {
        return music;
    }
    /**
     * @brief Play the music
     */
    void play()
    {
        music.play();
        status = Playing;
    }
    /**
     * @brief Pause the music
     */
    void pause()
    {
        music.pause();
        status = Paused;
    }
    /**
     * @brief Stop the music
     */
    void stop()
    {
        music.stop();
        status = Stopped;
    }
    /**
     * @brief Get the volume of the music
     *
     * @return float The volume
     */
    void setVolume(float volume)
    {
        if (volume > 100)
            volume = 100;
        if (volume < 0)
            volume = 0;
        music.setVolume(volume);
        _volume = volume;
    }
    /**
     * @brief Make the music loop
     *
     * @param is_looping If the music is looping
     */
    void setLoop(bool is_looping)
    {
        music.setLoop(is_looping);
        _is_looping = is_looping;
    }
    /**
     * @brief Get the status of the music
     */
    const Status& getStatus() const
    {
        return (status);
    };
    /**
     * @brief Update the status of the music
     */
    void updateStatus()
    {
        status = (Status)music.getStatus();
    }

private:
    float _volume;
    bool _is_looping;
    sf::Music music;
    Status status;
};
}