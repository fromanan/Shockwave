#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern Shockwave::Application* Shockwave::CreateApplication();

int main(int argc, char** argv)
{
	Shockwave::Log::Init();
	
	SW_CORE_INFO("Shockwave (Version 0.0.1a - 9/21/2023)\n");
	auto app = Shockwave::CreateApplication();
	app->Run();
	delete app;
}

#endif