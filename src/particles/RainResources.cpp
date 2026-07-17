#include "particles/RainResources.h"
#include "graphics/QuadMesh.h"
#include "graphics/Shader.h"
#include "graphics/Material.h"
#include "graphics/Texture.h"

//std::shared_ptr<QuadMesh> RainResources::m_mesh = nullptr;
std::shared_ptr<Mesh> RainResources::m_mesh = nullptr;

std::shared_ptr<Shader> RainResources::m_shader = nullptr;

std::shared_ptr<Texture> RainResources::m_texture = nullptr;

std::shared_ptr<Material> RainResources::m_material = nullptr;

bool RainResources::initialize()
{
    // Ya está inicializado
    if (m_material)
    {
        return true;
    }

    //------------------------------------------
    // Mesh
    //------------------------------------------

    m_mesh = std::make_shared<QuadMesh>();

    //------------------------------------------
    // Shader
    //------------------------------------------

    m_shader = std::make_shared<Shader>();

    if (!m_shader->load(
            "assets/shaders/billboard/vertex.glsl",
            "assets/shaders/billboard/fragment.glsl"))
    {
        return false;
    }

    //------------------------------------------
    // Texture
    //------------------------------------------

    m_texture = std::make_shared<Texture>();

    if (!m_texture->load(
            "assets/textures/rain_alpha.png"))
    {
        return false;
    }

    //------------------------------------------
    // Material
    //------------------------------------------

    m_material =
        std::make_shared<Material>(
            m_shader
        );

    m_material->setTexture(
        m_texture
    );

    return true;
}

std::shared_ptr<Mesh> RainResources::getMesh()
{
    return m_mesh;
}

std::shared_ptr<Material> RainResources::getMaterial()
{
    return m_material;
}