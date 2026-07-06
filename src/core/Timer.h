//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_TIMER_H
#define CG_BILLBOARD_RAIN_TIMER_H

//#pragma once

class Timer
{
public:
    Timer();

    void update();

    float getDeltaTime() const;
    float getTime() const;
    float getFPS() const;

private:
    float m_deltaTime;
    float m_lastTime;
    float m_time;
    float m_fps;
    float m_fpsTimer;
    int   m_frameCount;
};

#endif //CG_BILLBOARD_RAIN_TIMER_H