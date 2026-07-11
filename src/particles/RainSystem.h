#ifndef CG_BILLBOARD_RAIN_RAINSYSTEM_H
#define CG_BILLBOARD_RAIN_RAINSYSTEM_H

#include "particles/ParticleEmitter.h"
#include "particles/RainResources.h"

class Scene;

class RainSystem
{
public:

    RainSystem() = default;

    void initialize(Scene& scene);

    void update(float deltaTime);

private:

    ParticleEmitter m_emitter;
};

#endif