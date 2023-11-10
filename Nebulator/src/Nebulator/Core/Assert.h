#pragma once

#include "Core.h"
#include "Log.h"


#ifdef NR_ENABLE_ASSERTS
    #define NR_ASSERT(condition)  if(!(condition)) { NR_ERROR("ASSERTION FAILED!\n"); NR_WARN("\tFile: {0}\n\tLine: {1}", __FILE__, __LINE__); NR_DEBUGBREAK(); }
    #define NR_CORE_ASSERT(condition)  if(!(condition)) { NR_CORE_ERROR("ASSERTION FAILED!\n"); NR_CORE_WARN("\tFile: {0}\n\tLine: {1}", __FILE__, __LINE__); NR_DEBUGBREAK(); }
#else 
    #define NR_ASSERT(condition)
    #define NR_CORE_ASSERT(condition)
#endif // NR_DEBUG_ASSERTS