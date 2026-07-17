#include "scene/GroundResources.h"

#include "graphics/GroundMesh.h"
#include "graphics/QuadMesh.h"
#include "graphics/Shader.h"
#include "graphics/Material.h"
#include "graphics/Texture.h"

std::shared_ptr<Mesh> GroundResources::m_mesh = nullptr;

std::shared_ptr<Shader> GroundResources::m_shader = nullptr;

std::shared_ptr<Texture> GroundResources::m_texture = nullptr;

std::shared_ptr<Material> GroundResources::m_material = nullptr;

bool GroundResources::initialize()
{
    std::cout << "GroundResources::initialize()\n";
    if (m_material)
    {
        std::cout << "Already initialized\n";
        return true;
    }

    //---------------------------------
    // Mesh
    //---------------------------------

    m_mesh = std::make_shared<GroundMesh>();

    //---------------------------------
    // Shader
    //---------------------------------

    m_shader = std::make_shared<Shader>();

    if (!m_shader->load(
            "assets/shaders/ground/vertex.glsl",
            "assets/shaders/ground/fragment.glsl"))
    {
        std::cout << "Ground shader OK\n";
        return false;
    }

    //---------------------------------
    // Texture
    //---------------------------------

    m_texture = std::make_shared<Texture>();
    std::cout << "Cargando: assets/textures/ground.jpg" << std::endl;
    if (!m_texture->load(
            "assets/textures/ground.jpg"))
    {
        return false;
    }
    std::cout << "Texture ID: " << m_texture.get() << std::endl;

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

std::shared_ptr<Mesh> GroundResources::getMesh()
{
    return m_mesh;
}

std::shared_ptr<Material> GroundResources::getMaterial()
{
    return m_material;
}