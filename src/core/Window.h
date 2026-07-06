//
// Created by DIEGO on 06/07/2026.
//

#ifndef CG_BILLBOARD_RAIN_WINDOW_H
#define CG_BILLBOARD_RAIN_WINDOW_H

//#pragma once

#include <string>

struct GLFWwindow; //forward declaracion

class Window
{
public:
    Window();
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    bool initialize();

    void shutdown();

    void pollEvents();

    void swapBuffers();

    bool shouldClose() const;

    GLFWwindow* getNativeWindow() const;

    int getWidth() const;
    int getHeight() const;

private:
    GLFWwindow* m_window;

    int m_width;
    int m_height;

    std::string m_title;
};


#endif //CG_BILLBOARD_RAIN_WINDOW_H