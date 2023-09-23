#include "Shockwave.h"

class ExampleLayer : public Shockwave::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SW_INFO("ExampleLayer::Update");
	}

	void OnEvent(Shockwave::Event& event) override
	{
		SW_TRACE("{0}", event);
	}
};

class Sandbox : public Shockwave::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Shockwave::ImGuiLayer());
	}

	~Sandbox() override = default;
};

Shockwave::Application* Shockwave::CreateApplication()
{
	return new Sandbox();
}