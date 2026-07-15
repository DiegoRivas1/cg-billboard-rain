#include "particles/RainSystem.h"

#include "scene/Scene.h"

void RainSystem::initialize(Scene& scene)
{
    RainResources::initialize();

    m_emitter.setSpawnArea(
        20.0f,   // ancho
        20.0f,   // profundidad
        12.0f    // altura
    );

    m_emitter.initialize(
        scene,
        m_particleCount      // 1000  número inicial de gotas
    );
}

void RainSystem::update(float deltaTime)
{
    m_emitter.update(deltaTime);
}

void RainSystem::setCenter(const glm::vec3& center)
{
    m_emitter.setCenter(center);
}

void RainSystem::setWind(float wind)
{
    m_emitter.setWind(wind);
}

void RainSystem::rebuild(Scene& scene, int particleCount)
{
    m_particleCount = particleCount;

    scene.clear();

    m_emitter.clear();

    initialize(scene);
}