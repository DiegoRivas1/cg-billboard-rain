#include "resources/Resources.h"

#include "graphics/Mesh.h"
#include "graphics/Material.h"

std::shared_ptr<Mesh> Resources::getMesh() const
{
    return m_mesh;
}

std::shared_ptr<Material> Resources::getMaterial() const
{
    return m_material;
}