#include "LayerStack.h"

namespace Onyx::Engine::Components
{
  LayerStack::LayerStack()
  {}

  void LayerStack::PushLayer(Layer* layer)
  {
    layers_.push_back(layer);
  }

  void LayerStack::UpdateLayers()
  {
    for (auto layer : layers_)
    {
      layer->Update();
    }
  }
}
