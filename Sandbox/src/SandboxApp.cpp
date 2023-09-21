#include "Shockwave.h"

class Sandbox : public Shockwave::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Shockwave::Application* Shockwave::CreateApplication()
{
	return new Sandbox();
}