#include "scene/TreeSystem.h"

#include <cstdlib>

#include "scene/Scene.h"
#include "scene/Tree.h"

bool TreeSystem::initialize(Scene& scene)
{
    m_trees.clear();

    for (int i = 0; i < m_treeCount; i++)
    {
        auto tree = std::make_shared<Tree>();

        float x =
            ((float)rand() / RAND_MAX * 2.0f - 1.0f)
            * m_radius;

        float z =
            ((float)rand() / RAND_MAX * 2.0f - 1.0f)
            * m_radius;

        tree->transform.position =
            glm::vec3(
                x,
                2.2f,
                z
            );

        scene.add(tree);

        m_trees.push_back(tree);
    }

    return true;
}

void TreeSystem::update()
{

}