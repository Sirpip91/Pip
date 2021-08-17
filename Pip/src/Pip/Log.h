#pragma once


#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pip {

	class PIP_API Log
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
//macro for CORE log messages
#define PIP_CORE_TRACE(...) ::Pip::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PIP_CORE_INFO(...)  ::Pip::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PIP_CORE_WARN(...)  ::Pip::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PIP_CORE_ERROR(...) ::Pip::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PIP_CORE_FATAL(...) ::Pip::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//macro for Client log messages
#define PIP_TRACE(...)      ::Pip::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PIP_INFO(...)       ::Pip::Log::GetClientLogger()->info(__VA_ARGS__)
#define PIP_WARN(...)       ::Pip::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PIP_ERROR(...)      ::Pip::Log::GetClientLogger()->error(__VA_ARGS__)
#define PIP_FATAL(...)      ::Pip::Log::GetClientLogger()->fatal(__VA_ARGS__)

// IF DIST BUILD put here
