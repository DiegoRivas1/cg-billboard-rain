#ifndef CG_BILLBOARD_RAIN_GROUNDRESOURCES_H
#define CG_BILLBOARD_RAIN_GROUNDRESOURCES_H

#include <memory>
#include <iostream>
class Mesh;
class Shader;
class Material;
class Texture;

class GroundResources
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

#endif //CG_BILLBOARD_RAIN_GROUNDRESOURCES_H