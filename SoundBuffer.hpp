#pragma once


#include <SFML/Audio/SoundBuffer.hpp>
#include "RuntimeException.hpp"

namespace SFML {
    class SoundBuffer {
    public:
        SoundBuffer(const std::string &filename) : sound_buffer() {
            if (!sound_buffer.loadFromFile(filename))
                throw RuntimeException("SoundBuffer::ctor", "sound_buffer.loadFromFile failed, filename must be invalid");
        }
        const sf::SoundBuffer &getSoundBuffer() const {
            return sound_buffer;
        }
    private:
        sf::SoundBuffer sound_buffer;
    };
}
