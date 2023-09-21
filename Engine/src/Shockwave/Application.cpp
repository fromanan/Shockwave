#include "swpch.h"
#include "Application.h"

#include "Shockwave/Events/ApplicationEvent.h"
#include "Shockwave/Log.h"

namespace Shockwave
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SW_TRACE(e);

		while (true);
	}
}