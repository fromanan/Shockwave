#pragma once

// ReSharper disable CppClangTidyClangDiagnosticUnusedMacros, CppClangTidyModernizeMacroToEnum

// Imported from glfw3.h

/*! @defgroup gamepad_buttons Gamepad buttons
 *  @brief Gamepad buttons.
 *
 *  See @ref gamepad for how these are used.
 *
 *  @ingroup input
 *  @{ */
#define SW_GAMEPAD_BUTTON_A               0
#define SW_GAMEPAD_BUTTON_B               1
#define SW_GAMEPAD_BUTTON_X               2
#define SW_GAMEPAD_BUTTON_Y               3
#define SW_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define SW_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define SW_GAMEPAD_BUTTON_BACK            6
#define SW_GAMEPAD_BUTTON_START           7
#define SW_GAMEPAD_BUTTON_GUIDE           8
#define SW_GAMEPAD_BUTTON_LEFT_THUMB      9
#define SW_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define SW_GAMEPAD_BUTTON_DPAD_UP         11
#define SW_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define SW_GAMEPAD_BUTTON_DPAD_DOWN       13
#define SW_GAMEPAD_BUTTON_DPAD_LEFT       14
#define SW_GAMEPAD_BUTTON_LAST            SW_GAMEPAD_BUTTON_DPAD_LEFT

#define SW_GAMEPAD_BUTTON_CROSS       SW_GAMEPAD_BUTTON_A
#define SW_GAMEPAD_BUTTON_CIRCLE      SW_GAMEPAD_BUTTON_B
#define SW_GAMEPAD_BUTTON_SQUARE      SW_GAMEPAD_BUTTON_X
#define SW_GAMEPAD_BUTTON_TRIANGLE    SW_GAMEPAD_BUTTON_Y
/*! @} */

/*! @defgroup gamepad_axes Gamepad axes
 *  @brief Gamepad axes.
 *
 *  See @ref gamepad for how these are used.
 *
 *  @ingroup input
 *  @{ */
#define SW_GAMEPAD_AXIS_LEFT_X        0
#define SW_GAMEPAD_AXIS_LEFT_Y        1
#define SW_GAMEPAD_AXIS_RIGHT_X       2
#define SW_GAMEPAD_AXIS_RIGHT_Y       3
#define SW_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define SW_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define SW_GAMEPAD_AXIS_LAST          SW_GAMEPAD_AXIS_RIGHT_TRIGGER
/*! @} */
