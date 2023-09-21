#pragma once

#include "Core.h"

#include "Window.h"
#include "Shockwave/LayerStack.h"
#include "Shockwave/Events/Event.h"
#include "Shockwave/Events/ApplicationEvent.h"

namespace Shockwave
{
	class SHOCKWAVE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined by CLIENT
	Application* CreateApplication();
}

