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

    void setCenter(const glm::vec3& center);

    void setWind(float wind);

    void rebuild(Scene& scene, int particleCount);

    void setSpeedMultiplier(float multiplier);

private:

    ParticleEmitter m_emitter;
    int m_particleCount = 1000;
};

#endif