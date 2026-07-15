#include "particles/ParticleEmitter.h"

#include <cstdlib>

#include "particles/RainParticle.h"
#include "scene/Scene.h"

ParticleEmitter::ParticleEmitter() = default;

void ParticleEmitter::initialize(
    Scene& scene,
    int particleCount)
{
    m_scene = &scene;

    m_particles.reserve(particleCount);

    for (int i = 0; i < particleCount; ++i)
    {
        auto particle = std::make_shared<RainParticle>();

        particle->reset(
            randomSpawnPosition()
        );

        //particle->update(static_cast<float>(rand()) / RAND_MAX * 5.0f);
        particle->setLifetime(
    static_cast<float>(rand()) / RAND_MAX * particle->getMaxLifetime() );

        particle->setWind(m_wind);

        scene.add(particle);

        m_particles.push_back(particle);
    }
}

void ParticleEmitter::update(float deltaTime)
{
    for (auto& particle : m_particles)
    {
        particle->update(deltaTime);

        if (!particle->isAlive())
        {
            particle->reset(
                randomSpawnPosition()
            );
        }
    }
}

void ParticleEmitter::setSpawnArea(
    float width,
    float depth,
    float height)
{
    m_width = width;
    m_depth = depth;
    m_height = height;
}

void ParticleEmitter::setCenter(const glm::vec3& center)
{
    m_center = center;
}

void ParticleEmitter::setWind(float wind)
{
    m_wind = wind;

    for (auto& particle : m_particles)
    {
        particle->setWind(wind);
    }
}

void ParticleEmitter::clear()
{
    m_particles.clear();
}

glm::vec3 ParticleEmitter::randomSpawnPosition() const
{
    float x =
        (static_cast<float>(rand()) / RAND_MAX - 0.5f)
        * m_width;

    float z =
        (static_cast<float>(rand()) / RAND_MAX - 0.5f)
        * m_depth;

    float y =
        (static_cast<float>(rand()) / RAND_MAX)
        * m_height;

    return m_center + glm::vec3(x, y, z);
}