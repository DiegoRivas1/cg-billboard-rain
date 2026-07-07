//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_SCENEOBJECT_H
#define CG_BILLBOARD_RAIN_SCENEOBJECT_H
//#pragma once
#include  <memory>
#include "scene/Transform.h"
#include "graphics/Mesh.h"
#include "graphics/Material.h"
class Shader;

class SceneObject
{
public:

    SceneObject() = default;

    virtual ~SceneObject() = default;

    virtual void update(float deltaTime) {}

    virtual void render(const Renderer& renderer);

    Transform transform;

    std::shared_ptr<Mesh> mesh;

    std::shared_ptr<Material> material;

};
#endif //CG_BILLBOARD_RAIN_SCENEOBJECT_H