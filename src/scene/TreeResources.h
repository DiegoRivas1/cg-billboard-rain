#ifndef CG_BILLBOARD_RAIN_TREERESOURCES_H
#define CG_BILLBOARD_RAIN_TREERESOURCES_H
//#pragma once

#include <memory>

class Mesh;
class Shader;
class Texture;
class Material;

class TreeResources
{
public:

    static bool initialize();

    static std::shared_ptr<Mesh> getMesh();

    static std::shared_ptr<Material> getMaterial();

private:

    static std::shared_ptr<Mesh> m_mesh;

    static std::shared_ptr<Shader> m_shader;

    static std::shared_ptr<Texture> m_texture;

    static std::shared_ptr<Material> m_material;
};
#endif //CG_BILLBOARD_RAIN_TREERESOURCES_H