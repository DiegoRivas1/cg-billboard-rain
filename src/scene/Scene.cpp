#include "scene/Scene.h"

void Scene::add(std::shared_ptr<SceneObject> object)
{
    m_objects.push_back(std::move(object));
}

void Scene::render()
{
    for (const auto& object : m_objects)
    {
        object->render();
    }
}