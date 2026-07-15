#include "particles/RainParticle.h"
#include "particles/RainResources.h"


RainParticle::RainParticle()
    : m_velocity(0.0f, -10.0f, 0.0f),
      m_lifetime(0.0f),
      m_maxLifetime(5.0f)
{
    mesh = RainResources::getMesh();
    material = RainResources::getMaterial();

    transform.scale = glm::vec3(
        0.03f,
        0.18f,
        1.0f
    );
}


void RainParticle::update(float deltaTime)
{
    if (!isAlive())
        return;


    transform.position +=
        m_velocity * m_speedMultiplier * deltaTime;


    m_lifetime -= deltaTime;
}



void RainParticle::reset(const glm::vec3& position)
{
    transform.position = position;


    m_lifetime = m_maxLifetime;

    float speed = 8.0f + static_cast<float>(rand()) / RAND_MAX * 6.0f;

    m_velocity =
        glm::vec3(
            m_wind,//viento
            -speed, //-10.0f,
            0.0f
        );

    float s = 0.02f + static_cast<float>(rand()) / RAND_MAX * 0.02f;

    transform.scale =
        glm::vec3(
            s,
            s * 5.0f,
            1.0f
        );
}



bool RainParticle::isAlive() const
{
    return m_lifetime > 0.0f;
}

void RainParticle::setLifetime(float lifetime)
{
    m_lifetime = lifetime;
}

void RainParticle::setWind(float wind)
{
    m_wind = wind;
}

void RainParticle::setSpeedMultiplier(float multiplier)
{
    m_speedMultiplier = multiplier;
}


float RainParticle::getLifetime() const
{
    return m_lifetime;
}

float RainParticle::getMaxLifetime() const
{
    return m_maxLifetime;
}