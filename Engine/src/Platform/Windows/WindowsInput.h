#pragma once

#include "WindowsWindow.h"
#include "Shockwave/Application.h"
#include "Shockwave/Input/Input.h"

namespace Shockwave
{
    class WindowsInput : public Input
    {
    protected:
        bool IsKeyPressedImpl(int keycode) override;
        bool IsMouseButtonPressedImpl(int button) override;
        std::pair<float, float> GetMouseImpl() override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;

        static GLFWwindow* GetWindow() { return static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow()); }
    };
}
