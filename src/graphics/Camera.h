//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_CAMERA_H
#define CG_BILLBOARD_RAIN_CAMERA_H

//#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();

    void update(float dt);

    void setAspectRatio(float aspect);

    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;

    void processMouse(float xoffset, float yoffset);
    void processKeyboard(const glm::vec3& direction, float dt);

private:
    void updateVectors();

private:
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;

    float m_yaw;
    float m_pitch;

    float m_speed;
    float m_sensitivity;

    float m_aspectRatio;

    glm::mat4 m_view;
    glm::mat4 m_projection;
};

#endif //CG_BILLBOARD_RAIN_CAMERA_H