#pragma once

#ifdef NR_DEBUG

    #ifdef NR_PLATFORM_WINDOWS
        #define NR_DEBUGBREAK() __debugbreak()
    #else
        #error Only Nebulator only supports Windows at the moment
    #endif // NR_PLATFORM_WINDOWS
    

    #define NR_ENABLE_ASSERTS

#else 
    #define NR_DEBUGBREAK()

#endif // NR_DEBUG

#define BIT(x) (1 << x)

#include "Nebulator/Core/Log.h"
#include "Nebulator/Core/Assert.h"