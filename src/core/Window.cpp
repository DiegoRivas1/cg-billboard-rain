//
// Created by DIEGO on 06/07/2026.
//

#include "core/Window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window()
    : m_window(nullptr),
      m_width(1280),
      m_height(720),
      m_title("cg-billboard-rain")
{
}

Window::~Window()
{
    shutdown();
}

bool Window::initialize()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW.\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(
        m_width,
        m_height,
        m_title.c_str(),
        nullptr,
        nullptr);

    if (!m_window)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD.\n";

        glfwDestroyWindow(m_window);
        glfwTerminate();

        return false;
    }

    glfwSwapInterval(1);

    return true;
}

void Window::shutdown()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    glfwTerminate();
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapBuffers()
{
    glfwSwapBuffers(m_window);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::getNativeWindow() const
{
    return m_window;
}

int Window::getWidth() const
{
    return m_width;
}

int Window::getHeight() const
{
    return m_height;
}