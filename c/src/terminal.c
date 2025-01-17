#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "../include/terminal.h"

#ifdef WIN32
    #include <windows.h>
#endif

win_size get_win_size() {
    #ifdef WIN32
        // Get screen information from windows kernel
        CONSOLE_SCREEN_BUFFER_INFO terminal_buffer;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &terminal_buffer);

        return (win_size) {
            // Access the terminal screen limit coordinates
            .width = (size_t) terminal_buffer.srWindow.Right - terminal_buffer.srWindow.Left + 1,
            .height = (size_t) terminal_buffer.srWindow.Bottom - terminal_buffer.srWindow.Top + 1
        };
    #endif

    return (win_size) {0, 0};
}

void sleep_ms(const size_t milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / SECOND_MS;
    ts.tv_nsec = (milliseconds % (size_t) SECOND_MS) * SECOND_NS;

    nanosleep(&ts, NULL);
}

void handle_interruption(const int signal_code) {
    show_cursor();
    exit(EXIT_SUCCESS);
}

// TODO: Add things so any key the user presses, closes the program.
void handle_cursor() {
    signal(SIGINT, handle_interruption);
    hide_cursor();
}