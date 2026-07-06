#include "graphics/Material.h"

Material::Material(std::shared_ptr<Shader> shader)
    : m_shader(std::move(shader))
{
}

void Material::bind(const Renderer& renderer) const
{
    if (!m_shader)
        return;

    m_shader->use();

    m_shader->setMat4(
        "uView",
        renderer.getViewMatrix()
    );

    m_shader->setMat4(
        "uProjection",
        renderer.getProjectionMatrix()
    );
}

std::shared_ptr<Shader> Material::getShader() const
{
    return m_shader;
}

void Material::setShader(std::shared_ptr<Shader> shader)
{
    m_shader = std::move(shader);
}