#include "scene/Scene.h"

void Scene::add(std::shared_ptr<SceneObject> object)
{
    m_objects.push_back(std::move(object));
}

void Scene::render(const Renderer& renderer)
{
    for (const auto& object : m_objects)
    {
        object->render(renderer);
    }
}

void Scene::clear()
{
    m_objects.clear();
}