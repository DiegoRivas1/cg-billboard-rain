#include "scene/Ground.h"

#include "scene/GroundResources.h"

Ground::Ground()
{
    GroundResources::initialize();

    mesh = GroundResources::getMesh();

    material = GroundResources::getMaterial();

    transform.rotation.x = 0.0f;

    transform.scale = glm::vec3(
        1.0f
    );

    transform.position = glm::vec3(
        0.0f,
        0.0f,
        0.0f
    );
}