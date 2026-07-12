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

int GuiManager::getParticleCount() const
{
    return m_particleCount;
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

    ImGui::Text("FPS: (connect later)");
    ImGui::Text("Frame system active");

    ImGui::End();
}

void GuiManager::drawParticleWindow()
{
    ImGui::Begin("Particles");

    if (ImGui::SliderInt("Particles", &m_particleCount, 100, 5000))
    {
        m_particleCountChanged = true;
    }

    ImGui::End();
}

void GuiManager::drawRendererWindow()
{
    ImGui::Begin("Renderer");

    ImGui::Text("Renderer information.");

    ImGui::End();
}