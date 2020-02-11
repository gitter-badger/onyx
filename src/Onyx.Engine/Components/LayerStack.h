#pragma once
#include "Layer.h"

#include <vector>

namespace Onyx::Engine::Components
{
  class LayerStack
  {
  public:
    LayerStack();

    void PushLayer(Layer* layer);
  private:
    std::vector<Layer*> layers_;
  };
}
