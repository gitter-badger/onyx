#pragma once
#include "..\pch.h"

#include <GLFW\glfw3.h>

namespace Onyx::Engine::System
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		~WindowsWindow();

		void* GetWindowHandler() const override;
		std::string GetTitle() const override;
		void SetTitle(const std::string& title) override;
		void OnEvent(const WindowProperties::DispatchEventFunc& callback) override;
		void Update() override;
	private:
		WindowProperties window_properties_;
		GLFWwindow* window_;

		void Initialise();
		void Shutdown();
	};
}
