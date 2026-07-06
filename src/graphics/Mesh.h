//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_MESH_H
#define CG_BILLBOARD_RAIN_MESH_H
//#pragma once

#include <vector>

#include <glad/glad.h>

#include "graphics/Vertex.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();

    bool create(
        const std::vector<Vertex>& vertices,
        const std::vector<unsigned int>& indices
    );

    void draw() const;

    void destroy();

private:

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;

    GLsizei m_indexCount;
};
#endif //CG_BILLBOARD_RAIN_MESH_H