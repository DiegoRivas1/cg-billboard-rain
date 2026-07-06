//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_APPLICATION_H
#define CG_BILLBOARD_RAIN_APPLICATION_H

//#pragma once

#include "core/Renderer.h"
#include "core/Window.h"
#include "gui/GuiManager.h"
#include "core/Timer.h"
#include "graphics/Camera.h"

class Application
{
public:

    Application();
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    Application(Application&&) = delete;
    Application& operator=(Application&&) = delete;

    int run();

private:

    bool initialize();

    void processInput();

    void update();

    void render();

    void shutdown();

private:

    Window m_window;

    Renderer m_renderer;

    GuiManager m_gui;

    Timer m_timer;

    Camera m_camera;
};

#endif //CG_BILLBOARD_RAIN_APPLICATION_H