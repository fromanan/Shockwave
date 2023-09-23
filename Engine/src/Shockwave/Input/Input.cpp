#include "swpch.h"
#include "Input.h"

#include "KeyCodes.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

namespace Shockwave
{
    void Input::LoadKeyMap()
    {
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.KeyMap[ImGuiKey_Tab]			= SW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow]	= SW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow]	= SW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow]		= SW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow]	= SW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp]		= SW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown]	= SW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home]		= SW_KEY_HOME;
        io.KeyMap[ImGuiKey_End]			= SW_KEY_END;
        io.KeyMap[ImGuiKey_Insert]		= SW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete]		= SW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace]	= SW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space]		= SW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter]		= SW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape]		= SW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A]			= SW_KEY_A;
        io.KeyMap[ImGuiKey_C]			= SW_KEY_C;
        io.KeyMap[ImGuiKey_V]			= SW_KEY_V;
        io.KeyMap[ImGuiKey_X]			= SW_KEY_X;
        io.KeyMap[ImGuiKey_Y]			= SW_KEY_Y;
        io.KeyMap[ImGuiKey_Z]			= SW_KEY_Z;
    }

}
