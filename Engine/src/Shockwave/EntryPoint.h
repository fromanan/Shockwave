#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern Shockwave::Application* Shockwave::CreateApplication();

int main(int argc, char** argv)
{
	printf("Shockwave Engine\n");
	auto app = Shockwave::CreateApplication();
	app->Run();
	delete app;
}

#endif