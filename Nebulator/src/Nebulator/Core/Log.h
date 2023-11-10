#pragma once

#include "spdlog\spdlog.h"

namespace Nebulator {

    class Log
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


///---CORE Log Macros---------------
#define NR_CORE_TRACE(...)       Nebulator::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NR_CORE_INFO(...)        Nebulator::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NR_CORE_WARN(...)        Nebulator::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NR_CORE_ERROR(...)       Nebulator::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NR_CORE_CRITICAL(...)    Nebulator::Log::GetCoreLogger()->critical(__VA_ARGS__)
///----------------------------------


///---CLIENT Log Macros-------------
#define NR_TRACE(...)            Nebulator::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NR_INFO(...)             Nebulator::Log::GetClientLogger()->info(__VA_ARGS__)
#define NR_WARN(...)             Nebulator::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NR_ERROR(...)            Nebulator::Log::GetClientLogger()->error(__VA_ARGS__)
#define NR_CRITICAL(...)         Nebulator::Log::GetClientLogger()->critical(__VA_ARGS__)
///----------------------------------