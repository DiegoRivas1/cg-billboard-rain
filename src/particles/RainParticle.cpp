#include "particles/RainParticle.h"


RainParticle::RainParticle()
    :
    m_velocity(0.0f,-10.0f,0.0f),
    m_lifetime(0.0f),
    m_maxLifetime(5.0f)
{

}


void RainParticle::update(float deltaTime)
{
    if (!isAlive())
        return;


    transform.position +=
        m_velocity * deltaTime;


    m_lifetime -= deltaTime;
}



void RainParticle::reset(const glm::vec3& position)
{
    transform.position = position;


    m_lifetime = m_maxLifetime;


    m_velocity =
        glm::vec3(
            0.0f,
            -10.0f,
            0.0f
        );
}



bool RainParticle::isAlive() const
{
    return m_lifetime > 0.0f;
}