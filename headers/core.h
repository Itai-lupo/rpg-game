#pragma once



#if defined(_WIN32) || defined(_WIN64) // Windows

#elif defined(__ANDROID__)  // Android (implies Linux, so it must come first)

#elif defined(__linux__) // linux
    #include "linuxWindow.h"
    typedef raftelGraphicEngine::linuxWindow window;
    typedef GLFWwindow* windowPtr;
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1// Apple iOS
    
    #elif TARGET_OS_MAC == 1 // Apple OSX
    
    #endif
#else
    #error "platform not supported"
#endif

typedef int raftelId;
