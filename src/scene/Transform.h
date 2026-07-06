//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_TRANSFORM_H
#define CG_BILLBOARD_RAIN_TRANSFORM_H
//#pragma once

#include <glm/glm.hpp>

class Transform
{
public:

    Transform();

    glm::mat4 getModelMatrix() const;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
#endif //CG_BILLBOARD_RAIN_TRANSFORM_H