#pragma once

#include "RuntimeException.hpp"
#include "SoundBuffer.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace SFML {
/**
 * @brief A manager for sound_buffers
 */
class SoundBufferManager {
public:
    /**
     * @brief Register a sound_buffer
     *
     * @param id The ID of the sound_buffer
     * @param filename The path to the sound_buffer file
     */
    void registerSoundBuffer(const std::string& id, const std::string& filename)
    {
        if (sound_buffers.find(id) != sound_buffers.end())
            throw RuntimeException("SoundBufferManager::registerSoundBuffer", "A sound_buffer with this ID has already been registered");
        std::shared_ptr<SoundBuffer> sound_buffer = std::make_shared<SoundBuffer>(filename);
        sound_buffers.emplace(id, sound_buffer);
    }
    /**
     * @brief Get a sound_buffer
     *
     * @param id The ID of the sound_buffer
     * @return std::shared_ptr<SoundBuffer> The sound_buffer
     */
    std::shared_ptr<SoundBuffer> getSoundBuffer(const std::string& id)
    {
        if (sound_buffers.find(id) == sound_buffers.end())
            throw RuntimeException("SoundBufferManager::getSoundBuffer", "The ID provided doesn't match with any sound_buffer previously registered");
        return sound_buffers.at(id);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<SoundBuffer>> sound_buffers;
};
}