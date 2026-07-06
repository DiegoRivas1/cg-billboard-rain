#include "graphics/Material.h"

Material::Material(std::shared_ptr<Shader> shader)
    : m_shader(std::move(shader))
{
}

void Material::bind() const
{
    if (m_shader)
    {
        m_shader->use();
    }
}

std::shared_ptr<Shader> Material::getShader() const
{
    return m_shader;
}

void Material::setShader(std::shared_ptr<Shader> shader)
{
    m_shader = std::move(shader);
}