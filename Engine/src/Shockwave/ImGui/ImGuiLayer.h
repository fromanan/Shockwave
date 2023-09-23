#pragma once

#include "Shockwave/Layers/Layer.h"

#include "Shockwave/Events/ApplicationEvent.h"
#include "Shockwave/Events/MouseEvent.h"
#include "Shockwave/Events/KeyEvent.h"

namespace Shockwave
{
	class SHOCKWAVE_API ImGuiLayer final : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		bool OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(const MouseMovedEvent& e);
		bool OnMouseScrolledEvent(const MouseScrolledEvent& e);
		bool OnKeyPressedEvent(const KeyPressedEvent& e);
		bool OnKeyReleasedEvent(const KeyReleasedEvent& e);
		bool OnKeyTypedEvent(const KeyTypedEvent& e);
		bool OnWindowResizeEvent(const WindowResizeEvent& e);
	private:
		double m_Time = 0.0f;
	};
}