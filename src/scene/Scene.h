//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_SCENE_H
#define CG_BILLBOARD_RAIN_SCENE_H
//#pragma once

#include <memory>
#include <vector>

#include "scene/SceneObject.h"

class Scene
{
public:

    void add(std::shared_ptr<SceneObject> object);

    void render(const Renderer& renderer);

private:

    std::vector<std::shared_ptr<SceneObject>> m_objects;
};
#endif //CG_BILLBOARD_RAIN_SCENE_H