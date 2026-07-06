#include "scene/SceneObject.h"

#include "graphics/Material.h"
#include "graphics/Shader.h"

void SceneObject::render(const Renderer& renderer)
{
    if (!mesh || !material)
        return;

    material->bind(renderer);

    if (auto shader = material->getShader())
    {
        shader->setMat4(
            "uModel",
            transform.getModelMatrix()
        );
    }

    mesh->draw();
}