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
        float scale =
            4.5f +
            ((float)rand() / RAND_MAX) * 2.0f;

        //Gneracion de arboles que no se peguen
        float x;
        float z;

        bool validPosition;

        do
        {
            x =
                ((float)rand() / RAND_MAX * 2.0f - 1.0f)
                * m_radius;

            z =
                ((float)rand() / RAND_MAX * 2.0f - 1.0f)
                * m_radius;

            validPosition = true;

            for (const auto& other : m_trees)
            {
                glm::vec2 p1(x, z);

                glm::vec2 p2(
                    other->transform.position.x,
                    other->transform.position.z
                );

                if (glm::distance(p1, p2) < m_minDistance)
                {
                    validPosition = false;
                    break;
                }
            }

        }
        while (!validPosition);

        tree->transform.position =
            glm::vec3(
                x,
                0.0f,//scale * 0.5f
                z
            );

        tree->transform.scale = glm::vec3(scale, scale, 1.0f);
        //tree->transform.position.y = scale * 0.5f;

        scene.add(tree);

        m_trees.push_back(tree);
    }

    return true;
}

void TreeSystem::update(
    const glm::vec3& cameraPosition,
    const glm::vec3& cameraForward)
{
    for (auto& tree : m_trees)
    {
        glm::vec2 treePos(
            tree->transform.position.x,
            tree->transform.position.z
        );

        glm::vec2 camPos(
            cameraPosition.x,
            cameraPosition.z
        );

        float distance =
            glm::length(treePos - camPos);

        if (distance > m_radius)
        {
            float offsetX =
                ((float)rand() / RAND_MAX - 0.5f)
                * m_radius;

            float offsetZ =
                ((float)rand() / RAND_MAX)
                * m_radius;

            glm::vec3 newPos =
                cameraPosition
                + cameraForward * offsetZ;

            newPos.x += offsetX;

            float scale = tree->transform.scale.x;
            newPos.y = 0.0f; //scale * 0.5f

            tree->transform.position = newPos;
        }
    }
}