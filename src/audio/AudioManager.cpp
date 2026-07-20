#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>

#include "audio/AudioManager.h"

AudioManager::AudioManager() = default;

AudioManager::~AudioManager() = default;

bool AudioManager::initialize()
{
    if (ma_engine_init(nullptr, &m_engine) != MA_SUCCESS)
    {
        return false;
    }

    m_initialized = true;

    return true;
}

void AudioManager::shutdown()
{
    if (!m_initialized)
        return;

    ma_engine_uninit(&m_engine);

    m_initialized = false;
}

void AudioManager::update(float)
{
}

void AudioManager::playRainLoop()
{
}

void AudioManager::stopRainLoop()
{
}

void AudioManager::playThunder()
{
}

void AudioManager::setRainVolume(float)
{
}