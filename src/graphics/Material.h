//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_MATERIAL_H
#define CG_BILLBOARD_RAIN_MATERIAL_H

//#pragma once

#include <memory>

#include "graphics/Shader.h"
#include "core/Renderer.h"
#include "graphics/Texture.h"
class Material
{
public:

    Material() = default;

    explicit Material(std::shared_ptr<Shader> shader);

    void bind(const Renderer& renderer) const;

    std::shared_ptr<Shader> getShader() const;

    void setShader(std::shared_ptr<Shader> shader);

    void setTexture(std::shared_ptr<Texture> texture);
    std::shared_ptr<Texture> getTexture() const;

private:

    std::shared_ptr<Shader> m_shader;

    std::shared_ptr<Texture> m_texture;
};
#endif //CG_BILLBOARD_RAIN_MATERIAL_H