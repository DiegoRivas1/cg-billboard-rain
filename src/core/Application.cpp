#include "core/Application.h"
//#include "scene/Billboard.h"
//#include "particles/RainParticle.h"

#include <cstdlib>
#include <GLFW/glfw3.h>

#include "scene/Ground.h"
#include "scene/Tree.h"

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

    //Piso
    //auto ground = std::make_shared<Ground>();
    //m_scene.add(ground);
    m_ground = std::make_shared<Ground>();

    m_scene.add(m_ground);

    m_treeSystem.initialize(m_scene);

    m_rainSystem.initialize(m_scene);
    //

    return true;
}

/*
void Application::initializeScene()
{
    auto quad = std::make_shared<QuadMesh>();

    auto shader = std::make_shared<Shader>();

    shader->load(
        "assets/shaders/billboard/vertex.glsl",
        "assets/shaders/billboard/fragment.glsl");

    auto material = std::make_shared<Material>(shader);

    //auto object = std::make_shared<SceneObject>();
    //auto object = std::make_shared<Billboard>();
    auto object = std::make_shared<RainParticle>();
    object->transform.position =
    glm::vec3(0.0f, 5.0f, 0.0f);

    object->reset(
        glm::vec3(0.0f,5.0f,0.0f)
    );
    object->mesh = quad;
    object->material = material;

    m_scene.add(object);
}
*/

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
    float dt = m_timer.getDeltaTime();
    m_camera.update(dt);

    if (m_ground)
    {
        glm::vec3 pos = m_camera.getPosition();

        m_ground->transform.position.x = pos.x;
        m_ground->transform.position.z = pos.z;
    }

    if (m_gui.particleCountChanged())
    {
        m_rainSystem.rebuild(
            m_scene,
            m_gui.getParticleCount()
        );

        auto ground = std::make_shared<Ground>();
        m_scene.add(ground);
    }

    m_gui.setFPS(1.0f / dt);
    m_gui.setDeltaTime(dt);
    m_gui.setCameraPosition(m_camera.getPosition());

    m_rainSystem.setCenter(
        m_camera.getPosition()
    );

    m_rainSystem.setWind(
        m_gui.getWind()
    );

    m_rainSystem.setSpeedMultiplier(
        m_gui.getSpeed()
    );

    m_rainSystem.update(dt);


}

void Application::render()
{
    m_renderer.setViewProjection(
        m_camera.getViewMatrix(),
        m_camera.getProjectionMatrix()
    );

    m_renderer.setCameraVectors(
        m_camera.getRight(),
        m_camera.getUp(),
        m_camera.getForward()
    );

    m_renderer.beginFrame();

    m_scene.render(m_renderer);

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