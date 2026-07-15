#include "gui/GuiManager.h"
#include "core/Timer.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

bool GuiManager::initialize(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 330");

    return true;
}

void GuiManager::beginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();

    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
}

void GuiManager::draw()
{
    drawDemoWindow();

    drawStatisticsWindow();

    drawParticleWindow();

    drawRendererWindow();
}

void GuiManager::endFrame()
{
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(
        ImGui::GetDrawData()
    );
}

void GuiManager::shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();

    ImGui_ImplGlfw_Shutdown();

    ImGui::DestroyContext();
}

void GuiManager::setFPS(float fps)
{
    m_fps = fps;
}

void GuiManager::setDeltaTime(float dt)
{
    m_deltaTime = dt;
}

void GuiManager::setCameraPosition(const glm::vec3& position)
{
    m_cameraPosition = position;
}

int GuiManager::getParticleCount() const
{
    return m_particleCount;
}

float GuiManager::getWind() const
{
    return m_wind;
}

float GuiManager::getSpeed() const
{
    return m_speed;
}

bool GuiManager::particleCountChanged()
{
    bool changed = m_particleCountChanged;

    m_particleCountChanged = false;

    return changed;
}

void GuiManager::drawDemoWindow()
{
    ImGui::ShowDemoWindow();
}

void GuiManager::drawStatisticsWindow()
{
    ImGui::Begin("Statistics");

    ImGui::Text("FPS: %.1f", m_fps);
    ImGui::Text("Delta time: %.3f ms", m_deltaTime * 1000.0f);

    ImGui::Separator();

    ImGui::Text("Camera");
    ImGui::Text("X: %.2f", m_cameraPosition.x);
    ImGui::Text("Y: %.2f", m_cameraPosition.y);
    ImGui::Text("Z: %.2f", m_cameraPosition.z);


    ImGui::End();
}

void GuiManager::drawParticleWindow()
{
    ImGui::Begin("Particles");

    if (ImGui::SliderInt("Particles", &m_particleCount, 100, 5000))
    {
        m_particleCountChanged = true;
    }

    ImGui::SliderFloat(
        "Wind",
        &m_wind,
        -5.0f,
        5.0f
    );

    ImGui::SliderFloat(
        "Rain Speed",
        &m_speed,
        0.2f,
        3.0f
    );

    ImGui::End();
}

void GuiManager::drawRendererWindow()
{
    ImGui::Begin("Renderer");

    ImGui::Text("Renderer information.");

    ImGui::End();
}