#pragma once
#include "coreEventData.h"

namespace LTE
{
    struct WindowResizeData: public coreEventData
    {
        WindowResizeData(int width, int height, windowPieceId window):
            coreEventData(events::WindowResize), windowWidth(width), windowHeight(height), window(window){}

        int windowWidth, windowHeight;
        windowPieceId window;
    };
}