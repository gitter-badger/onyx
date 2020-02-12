#pragma once
#include "..\Components\Layer.h"

using namespace Onyx::Engine::Components;

namespace Onyx::Engine::Diagnostics
{
	class HUDLayer : public Layer
	{
	public:
		HUDLayer();
		~HUDLayer() = default;

		void Update() const override;
	};
}
