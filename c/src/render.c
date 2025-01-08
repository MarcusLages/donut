#include <stdlib.h>
#include <time.h>

#include "render.h"

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


char **initialize_framebuffer(const win_size window) {
    char **output = malloc(window.width * sizeof(char *));
    if(output == NULL) {
        perror("Could not allocate memory for output buffer.");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < window.width; i++) {
        output[i] = malloc(window.height * sizeof(char));

        if(output[i] == NULL) {
            perror("Could not allocate memory for output buffer.");
            exit(EXIT_FAILURE);
        }

        for (size_t j = 0; j < window.height; j++)
            output[i][j] = EMPTY_PIXEL;
    }
    
    return output;
}

void free_framebuffer(char **buffer, const win_size window) {
    if(buffer != NULL) {
        for (size_t i = 0; i < window.width; i++)
            free(buffer[i]);

        free(buffer);
    }
    
    // TODO: Create function to restore cursor using signal.h for cases when the user press ctrl+c
}

void render_frame(char **output, const win_size window) {
    // TODO: Instead of cleaning the terminal, put the cursor in the beginning of the terminal
    clear_terminal();
    
    // TODO: Instead of writing char by char, print the string
    for(size_t j = 0; j < window.height; j++) {
        for(size_t i = 0; i < window.width; i++) {
            putchar(output[i][j]);
            output[i][j] = EMPTY_PIXEL; // Clean screen buffer after printing
        }

        fflush(stdout); // Flush the stdout so it immediatelly prints the frame
    }
}

void sleep_ms(const size_t milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;

    nanosleep(&ts, NULL);
}

void handle_interruption(const int signal_code) {
    show_cursor();
    exit(EXIT_SUCCESS);
}