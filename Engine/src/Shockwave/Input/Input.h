﻿#pragma once

#include "Shockwave/Core.h"

namespace Shockwave
{
    class SHOCKWAVE_API Input
    {
    public:
        inline static bool IsKeyPressed(const int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
        inline static bool IsMouseButtonPressed(const int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static std::pair<float, float> GetMouse() { return s_Instance->GetMouseImpl(); }
        inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
        inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> GetMouseImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
    private:
        static Input* s_Instance;
    };
}