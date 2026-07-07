//
// Created by DIEGO on 07/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_BILLBOARD_H
#define CG_BILLBOARD_RAIN_BILLBOARD_H

//#pragma once

#include "scene/SceneObject.h"

class Billboard : public SceneObject
{
public:

    Billboard() = default;

    ~Billboard() override = default;

    void render(const Renderer& renderer) override;

protected:

    float m_width = 1.0f;
    float m_height = 1.0f;
};

#endif //CG_BILLBOARD_RAIN_BILLBOARD_H