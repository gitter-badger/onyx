#pragma once
#include "..\pch.h"
#include "..\Components\Layer.h"

using namespace Onyx::Engine::Components;
using namespace Onyx::Engine::System;

namespace Onyx::Engine::Diagnostics
{
	class HUDLayer : public Layer
	{
	public:
		HUDLayer(Window* window);
		~HUDLayer() = default;

		void Update() const override;
	};
}
