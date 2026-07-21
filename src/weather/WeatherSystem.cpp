#include "weather/WeatherSystem.h"

#include <cstdlib>

#include "audio/AudioManager.h"

bool WeatherSystem::initialize(AudioManager* audio)
{
    m_audio = audio;

    m_nextLightning =
        5.0f + (rand() % 6);

    return true;
}

void WeatherSystem::update(float dt)
{
    m_timer += dt;

    if (m_timer >= m_nextLightning)
    {
        triggerLightning();

        m_timer = 0.0f;

        m_nextLightning =
            5.0f +
            (rand() % 6);
    }

    if (m_flashTime > 0.0f)
    {
        m_flashTime -= dt;

        m_intensity =
            m_flashTime / 0.15f;

        if (m_intensity < 0.0f)
            m_intensity = 0.0f;
    }
}

void WeatherSystem::triggerLightning()
{
    m_flashTime = 0.15f;

    m_intensity = 1.0f;

    if (m_audio)
    {
        m_audio->playThunder();
    }
}

float WeatherSystem::getLightningIntensity() const
{
    return m_intensity;
}