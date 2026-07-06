#include "scene/SceneObject.h"

#include "graphics/Material.h"
#include "graphics/Shader.h"

void SceneObject::render()
{
    if (!mesh || !material)
    {
        return;
    }

    material->bind();

    if (auto shader = material->getShader())
    {
        shader->setMat4(
            "uModel",
            transform.getModelMatrix()
        );
    }

    mesh->draw();
}