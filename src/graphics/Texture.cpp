#include "graphics/Texture.h"

Texture::Texture() = default;

Texture::~Texture()
{
    destroy();
}

bool Texture::load(const std::string&)
{
    return true;
}

void Texture::bind(unsigned int) const
{
}

void Texture::destroy()
{
    if (m_id != 0)
    {
        glDeleteTextures(1, &m_id);
        m_id = 0;
    }
}