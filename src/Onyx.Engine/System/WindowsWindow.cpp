#include "..\pch.h"
#include "WindowsWindow.h"
#include "WindowCloseEvent.h"

namespace Onyx::Engine::System
{
	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		return std::make_unique<WindowsWindow>(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
		: window_properties_(properties)
	{
		Initialise();
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	std::string WindowsWindow::GetTitle() const
	{
		return window_properties_.Title;
	}

	void WindowsWindow::SetTitle(const std::string& title)
	{
		window_properties_.Title = title;
		glfwSetWindowTitle(window_, window_properties_.Title.c_str());
	}

	void WindowsWindow::OnEvent(const WindowProperties::DispatchEventFunc& callback)
	{
		window_properties_.DispatchEvent = callback;
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
	}

	void WindowsWindow::Initialise()
	{
		if (!glfwInit())
		{
			ONYX_LOG_ERROR("Could not initialise GLFW");
			return;
		}

		window_ = glfwCreateWindow(window_properties_.Width, window_properties_.Height, window_properties_.Title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window_, &window_properties_);
		glfwSwapInterval(1); // TODO: Don't hardcode V-Sync

		glfwSetWindowCloseCallback(window_, [](auto window)
		{
			auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			properties->DispatchEvent(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window_);
		glfwTerminate();
	}
}
