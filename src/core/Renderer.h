//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_RENDERER_H
#define CG_BILLBOARD_RAIN_RENDERER_H

//#pragma once

class Renderer
{
public:
    Renderer() = default;
    ~Renderer() = default;

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    bool initialize();

    void beginFrame();

    void endFrame();

    void shutdown();
};

#endif //CG_BILLBOARD_RAIN_RENDERER_H