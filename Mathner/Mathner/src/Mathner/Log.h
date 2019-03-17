#pragma once

#include "Mathner/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Mathner {

	class MATHNER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

//Core Log Macros
#define MN_CORE_ERROR(...)    ::Mathner::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MN_CORE_WARN(...)     ::Mathner::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MN_CORE_INFO(...)     ::Mathner::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MN_CORE_TRACE(...)    ::Mathner::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MN_CORE_CRITICAL(...) ::Mathner::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Core Log Macros
#define MN_ERROR(...)    ::Mathner::Log::GetClientLogger()->error(__VA_ARGS__)
#define MN_WARN(...)     ::Mathner::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MN_INFO(...)     ::Mathner::Log::GetClientLogger()->info(__VA_ARGS__)
#define MN_TRACE(...)    ::Mathner::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MN_CRITICAL(...) ::Mathner::Log::GetClientLogger()->critical(__VA_ARGS__)
