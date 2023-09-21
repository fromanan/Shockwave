#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Shockwave
{
	class SHOCKWAVE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by client
	Application* CreateApplication();
}

