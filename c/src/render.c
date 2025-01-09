#include <stdlib.h>
#include "../include/render.h"

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
}

void render_frame(char **output, const win_size window) {
    // TODO: Instead of cleaning the terminal, just put the cursor in the beginning of the terminal and flush stdout
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