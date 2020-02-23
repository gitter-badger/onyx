#include "HUDLayer.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>

namespace Onyx::Engine::Diagnostics
{
  HUDLayer::HUDLayer(Window* window)
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    
    auto glfw_window = static_cast<GLFWwindow*>(window.GetWindowHandler());
    ImGui_ImplGlfw_InitForVulkan(glfw_window, true);
  }

  void HUDLayer::Update() const
  {
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
  }
}
