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

#ifdef SW_ENABLE_ASSERTS

	#define SW_ASSERT(x, ...) { if(!(x)) { SW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define SW_CORE_ASSERT(x, ...) { if(!(x)) { SW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#else

	#define SW_ASSERT(x, ...)

	#define SW_CORE_ASSERT(x, ...)

#endif

#define BIND_EVENT_FN(x) std::bind((&x), this, std::placeholders::_1)

#define BIT(x) (1 << (x))
