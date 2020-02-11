#pragma once

namespace Onyx::Engine::Components
{
  class Layer
  {
  public:
    Layer();
    virtual ~Layer() = default;

    virtual void Update() const = 0;
  };
}
