#include "gui/GuiManager.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl2.h>

#include <GLFW/glfw3.h>

bool GuiManager::initialize(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL2_Init();

    return true;
}

void GuiManager::beginFrame()
{
    ImGui_ImplOpenGL2_NewFrame();

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

    ImGui_ImplOpenGL2_RenderDrawData(
        ImGui::GetDrawData()
    );
}

void GuiManager::shutdown()
{
    ImGui_ImplOpenGL2_Shutdown();

    ImGui_ImplGlfw_Shutdown();

    ImGui::DestroyContext();
}

void GuiManager::drawDemoWindow()
{
    ImGui::ShowDemoWindow();
}

void GuiManager::drawStatisticsWindow()
{
    ImGui::Begin("Statistics");

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

    ImGui::End();
}

void GuiManager::drawParticleWindow()
{
    ImGui::Begin("Particles");

    ImGui::Text("Particle system not implemented.");

    ImGui::End();
}

void GuiManager::drawRendererWindow()
{
    ImGui::Begin("Renderer");

    ImGui::Text("Renderer information.");

    ImGui::End();
}