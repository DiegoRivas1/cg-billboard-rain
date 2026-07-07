//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_RENDERER_H
#define CG_BILLBOARD_RAIN_RENDERER_H

#include <glm/glm.hpp>
#include "graphics/Shader.h"
//#pragma once

class Renderer
{
public:
    Renderer() = default;
    ~Renderer() = default;

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    bool initialize();

    void beginFrame();

    void endFrame();

    void shutdown();

    void setViewProjection(const glm::mat4& view, const glm::mat4& projection);
    void setCameraVectors(const glm::vec3& right, const glm::vec3& up, const glm::vec3& forward);
    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;

    const glm::vec3& getCameraRight() const;
    const glm::vec3& getCameraUp() const;
    const glm::vec3& getCameraForward() const;

    Shader& getShader();



private:
    glm::mat4 m_view = glm::mat4(1.0f);
    glm::mat4 m_projection = glm::mat4(1.0f);

    glm::vec3 m_cameraRight;
    glm::vec3 m_cameraUp;
    glm::vec3 m_cameraForward;

    Shader m_shader;
};

#endif //CG_BILLBOARD_RAIN_RENDERER_H