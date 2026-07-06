//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_MATERIAL_H
#define CG_BILLBOARD_RAIN_MATERIAL_H

//#pragma once

#include <memory>

#include "graphics/Shader.h"

class Material
{
public:

    Material() = default;

    explicit Material(std::shared_ptr<Shader> shader);

    void bind() const;

    std::shared_ptr<Shader> getShader() const;

    void setShader(std::shared_ptr<Shader> shader);

private:

    std::shared_ptr<Shader> m_shader;
};
#endif //CG_BILLBOARD_RAIN_MATERIAL_H