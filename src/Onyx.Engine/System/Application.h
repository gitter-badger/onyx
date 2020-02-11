#pragma once
#include "Window.h"
#include "Event.h"
#include "..\Components\LayerStack.h"

using namespace Onyx::Engine::Components;

namespace Onyx::Engine::System
{
  class Application
  {
  public:
    Application();
    ~Application();

    void Run();
  private:
    std::unique_ptr<Window> window_;
    LayerStack layer_stack_;
    bool is_running_;

    void HandleEvent(const Event& event);
  };
}
