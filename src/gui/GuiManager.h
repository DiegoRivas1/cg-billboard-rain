//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_GUIMANAGER_H
#define CG_BILLBOARD_RAIN_GUIMANAGER_H

//#pragma once

struct GLFWwindow;

class GuiManager
{
public:
    GuiManager() = default;
    ~GuiManager() = default;

    GuiManager(const GuiManager&) = delete;
    GuiManager& operator=(const GuiManager&) = delete;

    GuiManager(GuiManager&&) = delete;
    GuiManager& operator=(GuiManager&&) = delete;

    bool initialize(GLFWwindow* window);

    void beginFrame();

    void draw();

    void endFrame();

    void shutdown();

private:

    void drawDemoWindow();

    void drawStatisticsWindow();

    void drawParticleWindow();

    void drawRendererWindow();
};

#endif //CG_BILLBOARD_RAIN_GUIMANAGER_H