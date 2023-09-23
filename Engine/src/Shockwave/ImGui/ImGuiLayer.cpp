#include "swpch.h"

#include "ImGuiLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Needed manual imports after adding Input.cpp due to conflicts with Shockwave.h
#include "Shockwave/Input/Input.h"
#include "Shockwave/Input/KeyCodes.h"
#include "Shockwave/Application.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

// ReSharper disable CppClangTidyModernizeAvoidBind
namespace Shockwave
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {	}

	ImGuiLayer::~ImGuiLayer() = default;

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		Input::LoadKeyMap();

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach() { }

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		const Application& app = Application::Get();
		const Window& window = app.GetWindow();
		io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());

		const double time = glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? time - m_Time : 1.0f / 60.0f;
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		// Handled
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(const MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(const MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetXOffset();
		io.MouseWheelH += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(const KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;
		io.KeyCtrl = io.KeysDown[SW_KEY_LEFT_CONTROL] || io.KeysDown[SW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[SW_KEY_LEFT_SHIFT] || io.KeysDown[SW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[SW_KEY_LEFT_ALT] || io.KeysDown[SW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[SW_KEY_LEFT_SUPER] || io.KeysDown[SW_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(const KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(const KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		const int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter(keycode);

		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(const WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glad_glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}
