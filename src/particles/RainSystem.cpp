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
        1000      // número inicial de gotas
    );
}

void RainSystem::update(float deltaTime)
{
    m_emitter.update(deltaTime);
}