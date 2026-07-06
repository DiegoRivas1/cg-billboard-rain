/*
Application::~Application()
{
    shutdown();
}
*/

#include "core/Application.h"

#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application() = default;
Application::~Application() = default;

bool Application::initialize()
{
    if (!m_window.initialize())
    {
        return false;
    }

    if (!m_renderer.initialize())
    {
        return false;
    }

    if (!m_gui.initialize(m_window.getNativeWindow()))
    {
        return false;
    }

    return true;
}

int Application::run()
{
    if (!initialize())
    {
        return EXIT_FAILURE;
    }

    while (!m_window.shouldClose())
    {
        m_timer.update();

        processInput();
        update();
        render();
    }

    shutdown();

    return EXIT_SUCCESS;
}

void Application::processInput()
{
    m_window.pollEvents();

    glm::vec3 dir(0.0f);

    if (glfwGetKey(m_window.getNativeWindow(), GLFW_KEY_W) == GLFW_PRESS)
        dir.z = 1.0f;

    if (glfwGetKey(m_window.getNativeWindow(), GLFW_KEY_S) == GLFW_PRESS)
        dir.z = -1.0f;

    if (glfwGetKey(m_window.getNativeWindow(), GLFW_KEY_A) == GLFW_PRESS)
        dir.x = -1.0f;

    if (glfwGetKey(m_window.getNativeWindow(), GLFW_KEY_D) == GLFW_PRESS)
        dir.x = 1.0f;

    m_camera.processKeyboard(dir, m_timer.getDeltaTime());
}

void Application::update()
{
    m_camera.update(m_timer.getDeltaTime());
}

void Application::render()
{
    m_renderer.setViewProjection(
        m_camera.getViewMatrix(),
        m_camera.getProjectionMatrix()
    );

    m_renderer.beginFrame();

    m_renderer.getShader().use();
    m_renderer.getShader().setMat4("uView", m_camera.getViewMatrix());
    m_renderer.getShader().setMat4("uProjection", m_camera.getProjectionMatrix());

    m_gui.beginFrame();
    m_gui.draw();
    m_gui.endFrame();

    m_renderer.endFrame();

    m_window.swapBuffers();
}

void Application::shutdown()
{
    m_gui.shutdown();

    m_renderer.shutdown();

    m_window.shutdown();
}