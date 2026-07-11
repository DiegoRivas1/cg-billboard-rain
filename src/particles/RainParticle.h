//
// Created by DIEGO on 07/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_RAINPARTICLE_H
#define CG_BILLBOARD_RAIN_RAINPARTICLE_H
#include "scene/Billboard.h"

class RainParticle : public Billboard
{
public:

    RainParticle();

    ~RainParticle() override = default;


    void update(float deltaTime) override;


    void reset(const glm::vec3& position);


    bool isAlive() const;


private:

    glm::vec3 m_velocity;

    float m_lifetime;

    float m_maxLifetime;
};
#endif //CG_BILLBOARD_RAIN_RAINPARTICLE_H