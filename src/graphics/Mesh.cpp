#include "graphics/Mesh.h"
#include <cstddef>
Mesh::Mesh()
    : m_vao(0),
      m_vbo(0),
      m_ebo(0),
      m_indexCount(0)
{
}

Mesh::~Mesh()
{
    destroy();
}

bool Mesh::create(
    const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices)
{
    destroy();

    m_indexCount = static_cast<GLsizei>(indices.size());

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        vertices.data(),
        GL_STATIC_DRAW
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indices.size() * sizeof(unsigned int),
        indices.data(),
        GL_STATIC_DRAW
    );

    // Posición
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        reinterpret_cast<void*>(offsetof(Vertex, position))
    );

    // Coordenadas UV
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(
        1,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        reinterpret_cast<void*>(offsetof(Vertex, texCoord))
    );

    glBindVertexArray(0);

    return true;
}

void Mesh::draw() const
{
    glBindVertexArray(m_vao);

    glDrawElements(
        GL_TRIANGLES,
        m_indexCount,
        GL_UNSIGNED_INT,
        nullptr
    );

    glBindVertexArray(0);
}

void Mesh::destroy()
{
    if (m_ebo)
    {
        glDeleteBuffers(1, &m_ebo);
        m_ebo = 0;
    }

    if (m_vbo)
    {
        glDeleteBuffers(1, &m_vbo);
        m_vbo = 0;
    }

    if (m_vao)
    {
        glDeleteVertexArrays(1, &m_vao);
        m_vao = 0;
    }

    m_indexCount = 0;
}