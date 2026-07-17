#ifndef CG_BILLBOARD_RAIN_RESOURCES_H
#define CG_BILLBOARD_RAIN_RESOURCES_H

#include <memory>

class Mesh;
class Shader;
class Texture;
class Material;

class Resources
{
protected:

    static std::shared_ptr<Mesh> m_mesh;

    static std::shared_ptr<Shader> m_shader;

    static std::shared_ptr<Texture> m_texture;

    static std::shared_ptr<Material> m_material;

public:

    virtual ~Resources() = default;

    std::shared_ptr<Mesh> getMesh() const;

    std::shared_ptr<Material> getMaterial() const;
};

#endif //CG_BILLBOARD_RAIN_RESOURCES_H