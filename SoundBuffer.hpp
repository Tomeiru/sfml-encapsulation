#pragma once

#include "RuntimeException.hpp"
#include <SFML/Audio/SoundBuffer.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::SoundBuffer
 */
class SoundBuffer {
public:
    /**
     * @brief Construct a new Sound Buffer object
     *
     * @param filename The path to the sound buffer file
     */
    SoundBuffer(const std::string& filename)
        : sound_buffer()
    {
        if (!sound_buffer.loadFromFile(filename))
            throw RuntimeException("SoundBuffer::ctor", "sound_buffer.loadFromFile failed, filename must be invalid");
    }
    /**
     * @brief Get the Sound Buffer object
     *
     * @return const sf::SoundBuffer& The sound buffer
     */
    const sf::SoundBuffer& getSoundBuffer() const
    {
        return sound_buffer;
    }

private:
    sf::SoundBuffer sound_buffer;
};
}
