/*
Application::~Application()
{
    shutdown();
}
*/

#include "core/Application.h"

#include <cstdlib>

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
}

void Application::update()
{
}

void Application::render()
{
    m_renderer.beginFrame();

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