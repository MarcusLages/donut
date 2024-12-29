#include "render.h"

#ifdef WIN32
    #include <windows.h>
#endif

win_size get_win_size() {
    #ifdef WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

        return (win_size) {
            .width = (size_t) csbi.srWindow.Right - csbi.srWindow.Left + 1,
            .height = (size_t) csbi.srWindow.Bottom - csbi.srWindow.Top + 1
        };
    #endif

    return (win_size) {0, 0};
}