//
// Created by DIEGO on 19/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_AUDIOMANAGER_H
#define CG_BILLBOARD_RAIN_AUDIOMANAGER_H
#include <miniaudio.h>
#include <iostream>
class AudioManager
{
public:

    AudioManager();
    ~AudioManager();

    bool initialize();

    void shutdown();

    void update(float dt);

    void playRainLoop();

    void stopRainLoop();

    void playThunder();

    void setRainVolume(float volume);

    void setRainIntensity(float intensity);

private:

    ma_engine m_engine;

    ma_sound m_rainSound;

    bool m_initialized = false;
};
#endif //CG_BILLBOARD_RAIN_AUDIOMANAGER_H