//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_TEXTURE_H
#define CG_BILLBOARD_RAIN_TEXTURE_H
//#pragma once

#include <string>

#include <glad/glad.h>

class Texture
{
public:

    Texture();
    ~Texture();

    bool load(const std::string& filename);

    void bind(unsigned int unit = 0) const;

    void destroy();

private:

    GLuint m_id = 0;

    int m_width = 0;
    int m_height = 0;
    int m_channels = 0;
};
#endif //CG_BILLBOARD_RAIN_TEXTURE_H