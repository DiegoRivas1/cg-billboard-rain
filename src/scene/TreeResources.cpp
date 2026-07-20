#include "scene/TreeResources.h"

#include "graphics/QuadMesh.h"
#include "graphics/Shader.h"
#include "graphics/Material.h"
#include "graphics/Texture.h"

std::shared_ptr<Mesh> TreeResources::m_mesh = nullptr;

std::shared_ptr<Shader> TreeResources::m_shader = nullptr;

std::shared_ptr<Texture> TreeResources::m_texture = nullptr;

std::shared_ptr<Material> TreeResources::m_material = nullptr;

bool TreeResources::initialize()
{
    // Ya está inicializado
    if (m_material)
    {
        return true;
    }

    //---------------------------------
    // Mesh
    //---------------------------------

    m_mesh = std::make_shared<QuadMesh>();

    //---------------------------------
    // Shader
    //---------------------------------

    m_shader = std::make_shared<Shader>();

    if (!m_shader->load(
            "assets/shaders/tree/vertex.glsl",
            "assets/shaders/tree/fragment.glsl"))
    {
        return false;
    }

    //---------------------------------
    // Texture
    //---------------------------------

    m_texture = std::make_shared<Texture>();

    if (!m_texture->load(
            "assets/textures/tree.png"))
    {
        return false;
    }

    //---------------------------------
    // Material
    //---------------------------------

    m_material =
        std::make_shared<Material>(
            m_shader
        );

    m_material->setTexture(
        m_texture
    );

    return true;
}

std::shared_ptr<Mesh> TreeResources::getMesh()
{
    return m_mesh;
}

std::shared_ptr<Material> TreeResources::getMaterial()
{
    return m_material;
}