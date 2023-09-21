#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Shockwave
{
	class SHOCKWAVE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define SW_CORE_TRACE(...) ::Shockwave::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SW_CORE_INFO(...)  ::Shockwave::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SW_CORE_WARN(...)  ::Shockwave::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SW_CORE_ERROR(...) ::Shockwave::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SW_CORE_FATAL(...) ::Shockwave::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define SW_TRACE(...) ::Shockwave::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SW_INFO(...)  ::Shockwave::Log::GetClientLogger()->info(__VA_ARGS__)
#define SW_WARN(...)  ::Shockwave::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SW_ERROR(...) ::Shockwave::Log::GetClientLogger()->error(__VA_ARGS__)
#define SW_FATAL(...) ::Shockwave::Log::GetClientLogger()->critical(__VA_ARGS__)