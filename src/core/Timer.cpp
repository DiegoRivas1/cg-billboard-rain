#include "core/Timer.h"
#include <GLFW/glfw3.h>

Timer::Timer()
    : m_deltaTime(0.0f),
      m_lastTime(0.0f),
      m_time(0.0f),
      m_fps(0.0f),
      m_fpsTimer(0.0f),
      m_frameCount(0)
{
    m_lastTime = (float)glfwGetTime();
}

void Timer::update()
{
    float currentTime = (float)glfwGetTime();

    m_deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;

    m_time += m_deltaTime;

    // FPS
    m_frameCount++;
    m_fpsTimer += m_deltaTime;

    if (m_fpsTimer >= 1.0f)
    {
        m_fps = (float)m_frameCount / m_fpsTimer;
        m_frameCount = 0;
        m_fpsTimer = 0.0f;
    }
}

float Timer::getDeltaTime() const
{
    return m_deltaTime;
}

float Timer::getTime() const
{
    return m_time;
}

float Timer::getFPS() const
{
    return m_fps;
}