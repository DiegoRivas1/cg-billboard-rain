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

    m_shader.load("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

    return true;
}

void Renderer::beginFrame()
{
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

Shader& Renderer::getShader()
{
    return m_shader;
}