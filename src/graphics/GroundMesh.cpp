#include "graphics/GroundMesh.h"

GroundMesh::GroundMesh()
{
    std::vector<Vertex> vertices =
    {
        {{-10.0f, 0.0f,-10.0f}, {0.0f, 0.0f}},
        {{ 10.0f, 0.0f,-10.0f}, {20.0f,0.0f}},
        {{ 10.0f, 0.0f, 10.0f}, {20.0f,20.0f}},
        {{-10.0f, 0.0f, 10.0f}, {0.0f,20.0f}}
    };

    std::vector<unsigned int> indices =
    {
        0,1,2,
        2,3,0
    };

    create(vertices, indices);
}