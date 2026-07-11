#ifndef CG_BILLBOARD_RAIN_RAINRESOURCES_H
#define CG_BILLBOARD_RAIN_RAINRESOURCES_H

#include <memory>
#include "graphics/Mesh.h"
#include "graphics/QuadMesh.h"
#include "graphics/Material.h"
#include "graphics/Shader.h"
#include "graphics/Texture.h"

class QuadMesh;
class Shader;
class Material;
class Texture;

class RainResources
{
public:

    static bool initialize();

    //static std::shared_ptr<QuadMesh> getMesh();
    static std::shared_ptr<Mesh> getMesh();

    static std::shared_ptr<Material> getMaterial();

private:

    //static std::shared_ptr<QuadMesh> m_mesh;
    static std::shared_ptr<Mesh> m_mesh;
    static std::shared_ptr<Shader> m_shader;
    static std::shared_ptr<Texture> m_texture;
    static std::shared_ptr<Material> m_material;
};

#endif