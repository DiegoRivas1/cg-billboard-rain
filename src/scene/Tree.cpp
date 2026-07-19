#include "scene/Tree.h"
#include "scene/TreeResources.h"

Tree::Tree()
{
    TreeResources::initialize();

    mesh = TreeResources::getMesh();

    material = TreeResources::getMaterial();

    transform.scale = glm::vec3(
        4.0f,
        6.0f,
        1.0f
    );
}