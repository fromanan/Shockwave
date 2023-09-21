#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern Shockwave::Application* Shockwave::CreateApplication();

int main(int argc, char** argv)
{
	Shockwave::Log::Init();
	SW_CORE_WARN("Initialized Log!");
	int a = 5;
	SW_INFO("Hello! Var={0}", a);

	SW_CORE_INFO("Shockwave (Version 0.0.1 - 9/21/2023)\n");
	auto app = Shockwave::CreateApplication();
	app->Run();
	delete app;
}

#endif