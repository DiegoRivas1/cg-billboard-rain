//
// Created by DIEGO on 20/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_WEATHERSYSTEM_H
#define CG_BILLBOARD_RAIN_WEATHERSYSTEM_H
//#pragma once

class AudioManager;

class WeatherSystem
{
public:

    bool initialize(AudioManager* audio);

    void update(float dt);

    float getLightningIntensity() const;

private:

    void triggerLightning();

private:

    AudioManager* m_audio = nullptr;

    float m_timer = 0.0f;
    float m_nextLightning = 5.0f;

    float m_flashTime = 0.0f;

    float m_intensity = 0.0f;
};
#endif //CG_BILLBOARD_RAIN_WEATHERSYSTEM_H