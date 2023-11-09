#pragma once

#include "Core.h"   
#include "spdlog\spdlog.h"

namespace MapleStar {

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
#define MSTAR_CORE_TRACE(...)       MapleStar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MSTAR_CORE_INFO(...)        MapleStar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MSTAR_CORE_WARN(...)        MapleStar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MSTAR_CORE_ERROR(...)       MapleStar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MSTAR_CORE_CRITICAL(...)    MapleStar::Log::GetCoreLogger()->critical(__VA_ARGS__)
///----------------------------------


///---CLIENT Log Macros-------------
#define MSTAR_TRACE(...)            MapleStar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MSTAR_INFO(...)             MapleStar::Log::GetClientLogger()->info(__VA_ARGS__)
#define MSTAR_WARN(...)             MapleStar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MSTAR_ERROR(...)            MapleStar::Log::GetClientLogger()->error(__VA_ARGS__)
#define MSTAR_CRITICAL(...)         MapleStar::Log::GetClientLogger()->critical(__VA_ARGS__)
///----------------------------------