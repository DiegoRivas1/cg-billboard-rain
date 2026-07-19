#ifndef CG_BILLBOARD_RAIN_TREESYSTEM_H
#define CG_BILLBOARD_RAIN_TREESYSTEM_H
#include <memory>
#include <vector>
#include "scene/Tree.h"
//#pragma once

class Scene;

class TreeSystem
{
public:

    bool initialize(Scene& scene);

    void update(const glm::vec3& cameraPosition, const glm::vec3& cameraForward);
private:
    std::vector<std::shared_ptr<Tree>> m_trees;
    float m_radius = 40.0f;
    float m_minDistance = 6.0f;
    int m_treeCount = 30;
};
#endif //CG_BILLBOARD_RAIN_TREESYSTEM_H