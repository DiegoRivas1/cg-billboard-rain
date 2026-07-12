#ifndef CG_BILLBOARD_RAIN_PARTICLEEMITTER_H
#define CG_BILLBOARD_RAIN_PARTICLEEMITTER_H

#include <memory>
#include <vector>

#include <glm/glm.hpp>

class Scene;
class RainParticle;

class ParticleEmitter
{
public:

    ParticleEmitter();

    void initialize(
        Scene& scene,
        int particleCount
    );

    void update(float deltaTime);

    void setSpawnArea(
        float width,
        float depth,
        float height
    );

    void setCenter(const glm::vec3& center);

private:

    glm::vec3 randomSpawnPosition() const;

private:

    Scene* m_scene = nullptr;

    std::vector<std::shared_ptr<RainParticle>> m_particles;

    float m_width = 20.0f;
    float m_depth = 20.0f;
    float m_height = 10.0f;
    float m_wind = 0.5f;

    glm::vec3 m_center = glm::vec3(0.0f);
};

#endif