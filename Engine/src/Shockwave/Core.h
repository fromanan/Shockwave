#pragma once

#ifdef SW_PLATFORM_WINDOWS

	#ifdef SW_BUILD_DLL

		#define SHOCKWAVE_API __declspec(dllexport)

	#else

		#define SHOCKWAVE_API __declspec(dllimport)

	#endif

#else

	#error Shockwave only supports Windows!

#endif

#define BIT(x) (1 << x)
