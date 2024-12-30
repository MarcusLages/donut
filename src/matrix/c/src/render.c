#include <stdlib.h>
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
            output[i][j] = EMPTY_PIXEL;  // TODO: initialize with spaces constant
    }

    return output;
}

void free_framebuffer(char **buffer, const win_size window) {
    if(buffer != NULL) {
        for (size_t i = 0; i < window.width; i++)
            free(buffer[i]);

        free(buffer);
    }
}

void render_frame(char **output, const win_size window) {
    clear_terminal();
    
    for(size_t j = 0; j < window.height; j++) {
        for(size_t i = 0; i < window.width; i++) 
            putchar(output[i][j]);

        if(j != window.height - 1) putchar('\n');
    }
}