#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>

#include "audio/AudioManager.h"

#include <algorithm>

AudioManager::AudioManager() = default;

AudioManager::~AudioManager() = default;

bool AudioManager::initialize()
{
    if (ma_engine_init(nullptr, &m_engine) != MA_SUCCESS)
    {
        return false;
    }

    if (ma_sound_init_from_file(
            &m_engine,
            "assets/audio/rain_loop.wav",
            MA_SOUND_FLAG_STREAM,
            nullptr,
            nullptr,
            &m_rainSound) != MA_SUCCESS)
    {
        ma_engine_uninit(&m_engine);
        return false;
    }

    ma_sound_init_from_file(
    &m_engine,
    "assets/audio/thunder1.wav",
    0,
    nullptr,
    nullptr,
    &m_thunder1
);

    ma_sound_init_from_file(
        &m_engine,
        "assets/audio/thunder2.wav",
        0,
        nullptr,
        nullptr,
        &m_thunder2
    );

    ma_sound_init_from_file(
        &m_engine,
        "assets/audio/thunder3.wav",
        0,
        nullptr,
        nullptr,
        &m_thunder3
    );

    m_initialized = true;

    return true;
}

void AudioManager::shutdown()
{
    if (!m_initialized)
        return;

    ma_sound_uninit(&m_rainSound);
    ma_sound_uninit(&m_thunder1);
    ma_sound_uninit(&m_thunder2);
    ma_sound_uninit(&m_thunder3);

    ma_engine_uninit(&m_engine);

    m_initialized = false;
}

void AudioManager::update(float)
{
}

void AudioManager::playRainLoop()
{
    if (ma_sound_is_playing(&m_rainSound))
        return;

    ma_sound_set_looping(&m_rainSound, MA_TRUE);
    ma_sound_start(&m_rainSound);
}

void AudioManager::stopRainLoop()
{
    ma_sound_stop(&m_rainSound);
}

void AudioManager::playThunder()
{
    int id = rand() % 3;

    ma_sound* sound = nullptr;

    switch (id)
    {
    case 0:
        sound = &m_thunder1;
        break;

    case 1:
        sound = &m_thunder2;
        break;

    default:
        sound = &m_thunder3;
        break;
    }

    ma_sound_seek_to_pcm_frame(sound, 0);

    ma_sound_start(sound);
}

void AudioManager::setRainVolume(float volume)
{
    ma_sound_set_volume(
        &m_rainSound,
        volume
    );
}

void AudioManager::setRainIntensity(float intensity)
{
    intensity = std::clamp(intensity, 0.0f, 1.0f);

    //----------------------------------
    // Volumen
    //----------------------------------

    float volume =
        0.20f +
        intensity * 0.80f;

    ma_sound_set_volume(
        &m_rainSound,
        volume
    );

    //----------------------------------
    // Pitch
    //----------------------------------

    float pitch =
        1.0f +
        intensity * 0.05f;

    ma_sound_set_pitch(
        &m_rainSound,
        pitch
    );
}