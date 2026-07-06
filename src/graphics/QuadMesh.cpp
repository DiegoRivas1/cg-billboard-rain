#include "graphics/QuadMesh.h"

QuadMesh::QuadMesh()
{
    std::vector<Vertex> vertices =
    {
        {{-0.5f, -0.5f, 0.0f}},
        {{ 0.5f, -0.5f, 0.0f}},
        {{ 0.5f, 0.5f, 0.0f}},
        {{-0.5f, 0.5f, 0.0f}}
    };

    std::vector<unsigned int> indices =
    {
        0,1,2,
        2,3,0
    };

    create(vertices, indices);
}