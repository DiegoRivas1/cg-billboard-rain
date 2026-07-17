#include "graphics/Material.h"
#include <iostream>
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

    m_shader->setVec3(
        "uCameraRight",
        renderer.getCameraRight()
    );

    m_shader->setVec3(
        "uCameraUp",
        renderer.getCameraUp()
    );

    glActiveTexture(GL_TEXTURE0);

    if (m_texture)
    {
        //std::cout << "Binding own texture\n";
        m_texture->bind(0);
    }
    else
    {
        std::cout << "Binding texture 0\n";
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    m_shader->setInt("uTexture", 0);
}

std::shared_ptr<Shader> Material::getShader() const
{
    return m_shader;
}

std::shared_ptr<Texture> Material::getTexture() const
{
    return m_texture;
}

void Material::setShader(std::shared_ptr<Shader> shader)
{
    m_shader = std::move(shader);
}
void Material::setTexture(std::shared_ptr<Texture> texture)
{
    m_texture = std::move(texture);
}