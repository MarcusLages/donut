#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <unistd.h>

//* Rendering macros/constants
#define FONT_COLOUR_DEFAULT "\x1B[0m"
#define FONT_COLOUR_GREEN   "\x1B[1;32m"

#define CLEAR_STRING        "\033[H\033[2J\033[3J"

#define clear_terminal()    printf(CLEAR_STRING);

/**
 * Constructor that contains information about the terminal window size.
 * 
 * @param width     Width of terminal window.
 * @param height    Height of terminal window.
 */
typedef struct win_size {
    const size_t width;     // Width of terminal window.
    const size_t height;    // Height of terminal window.
} win_size;

//* Function prototypes
win_size get_win_size();

#endif //RENDER_H_