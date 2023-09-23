#include "swpch.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace Shockwave
{
    Input* Input::s_Instance = new WindowsInput();
    
    bool WindowsInput::IsKeyPressedImpl(const int keycode)
    {
        const auto window = GetWindow();
        const auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(const int button)
    {
        const auto window = GetWindow();
        const auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMouseImpl()
    {
        const auto window = GetWindow();
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return { xPos, yPos };
    }

    float WindowsInput::GetMouseXImpl()
    {
        return GetMouseImpl().first;
    }

    float WindowsInput::GetMouseYImpl()
    {
        return GetMouseImpl().second;
    }
}
