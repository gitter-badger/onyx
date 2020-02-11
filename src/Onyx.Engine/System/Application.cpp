#include "..\pch.h"
#include "Application.h"

namespace Onyx::Engine::System
{
	Application::Application()
	{
		ONYX_LOG_TRACE("Onyx Engine");
		window_ = Window::Create(WindowProperties());
		window_->OnEvent(std::bind(&Application::HandleEvent, this, std::placeholders::_1));

		layer_stack_ = Onyx::Engine::Components::LayerStack();
	}

	Application::~Application()
	{

	}

	void Application::AddLayer(Layer* layer)
	{
		layer_stack_.PushLayer(layer);
	}

	void Application::Run()
	{
		is_running_ = true;
		while (is_running_)
		{
			window_->Update();
		}
	}

	void Application::HandleEvent(const Event& event)
	{
		switch (event.GetType())
		{
			case EventType::WindowClose:
			{
				ONYX_LOG_TRACE("Window closed event");
				is_running_ = false;
			}
		}
	}
}
