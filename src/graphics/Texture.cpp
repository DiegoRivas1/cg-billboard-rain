#include "graphics/Texture.h"

#include <stb_image.h>

#include <iostream>

Texture::Texture() = default;

Texture::~Texture()
{
    destroy();
}

bool Texture::load(const std::string& filename)
{
    destroy();

    stbi_set_flip_vertically_on_load(true);

    unsigned char* data = stbi_load(
        filename.c_str(),
        &m_width,
        &m_height,
        &m_channels,
        0
    );

    if (!data)
    {
        std::cerr << "No se pudo cargar la textura: "
                  << filename
                  << std::endl;

        return false;
    }

    GLenum format = GL_RGB;

    if (m_channels == 1)
        format = GL_RED;

    else if (m_channels == 3)
        format = GL_RGB;

    else if (m_channels == 4)
        format = GL_RGBA;

    glGenTextures(1, &m_textureID);

    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        format,
        m_width,
        m_height,
        0,
        format,
        GL_UNSIGNED_BYTE,
        data
    );

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR_MIPMAP_LINEAR
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_LINEAR
    );

    stbi_image_free(data);

    return true;
}

void Texture::bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);

    glBindTexture(
        GL_TEXTURE_2D,
        m_textureID
    );
}

void Texture::destroy()
{
    if (m_textureID != 0)
    {
        glDeleteTextures(
            1,
            &m_textureID
        );

        m_textureID = 0;
    }
}