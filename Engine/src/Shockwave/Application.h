#pragma once

#include "Core.h"

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

