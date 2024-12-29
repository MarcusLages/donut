#include <stdlib.h>
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
            output[i][j] = '#';  // TODO: initialize with spaces constant
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