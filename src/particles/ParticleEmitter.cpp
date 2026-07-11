#include "particles/ParticleEmitter.h"

#include "particles/RainParticle.h"
#include "scene/Scene.h"

#include <cstdlib>

ParticleEmitter::ParticleEmitter() = default;

void ParticleEmitter::initialize(
    Scene& scene,
    int particleCount)
{
    m_scene = &scene;

    m_particles.reserve(particleCount);

    for (int i = 0; i < particleCount; i++)
    {
        auto particle =
            std::make_shared<RainParticle>();

        particle->reset(
            randomSpawnPosition()
        );

        m_scene->add(particle);

        m_particles.push_back(particle);
    }
}

void ParticleEmitter::update(float dt)
{
    for (auto& particle : m_particles)
    {
        particle->update(dt);

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

glm::vec3 ParticleEmitter::randomSpawnPosition() const
{
    float x =
        (static_cast<float>(rand()) / RAND_MAX - 0.5f)
        * m_width;

    float z =
        (static_cast<float>(rand()) / RAND_MAX - 0.5f)
        * m_depth;

    return glm::vec3(
        x,
        m_height,
        z
    );
}