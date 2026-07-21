#include "core/Renderer.h"

#include <glad/glad.h>

bool Renderer::initialize()
{
    glViewport(0, 0, 1280, 720);

    glClearColor(
        0.10f,
        0.12f,
        0.18f,
        1.0f
    );

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //m_shader.load("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

    return true;
}

void Renderer::beginFrame()
{
    if (m_lightningIntensity > 0.0f)
    {
        float flash = m_lightningIntensity;

        glClearColor(
            0.10f + flash * 0.80f,
            0.12f + flash * 0.78f,
            0.18f + flash * 0.72f,
            1.0f
        );
    }
    else
    {
        glClearColor(
            0.10f,
            0.12f,
            0.18f,
            1.0f
        );
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::endFrame()
{
    // Por ahora no hace nada.
}

void Renderer::shutdown()
{

}

void Renderer::setViewProjection(const glm::mat4& view, const glm::mat4& projection)
{
    m_view = view;
    m_projection = projection;
}
const glm::mat4& Renderer::getViewMatrix() const
{
    return m_view;
}

const glm::mat4& Renderer::getProjectionMatrix() const
{
    return m_projection;
}


void Renderer::setCameraVectors(const glm::vec3& right, const glm::vec3& up, const glm::vec3& forward)
{
    m_cameraRight = right;
    m_cameraUp = up;
    m_cameraForward = forward;
}

void Renderer::setLightningIntensity(float intensity)
{
    m_lightningIntensity = intensity;
}

const glm::vec3& Renderer::getCameraRight() const
{
    return m_cameraRight;
}

const glm::vec3& Renderer::getCameraUp() const
{
    return m_cameraUp;
}
const glm::vec3& Renderer::getCameraForward() const
{
    return m_cameraForward;
}