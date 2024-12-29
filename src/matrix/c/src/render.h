#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <unistd.h>

//* Rendering macros/constants
#define FONT_COLOUR_DEFAULT "\x1B[0m"                   // Default terminal font colour
#define FONT_COLOUR_GREEN   "\x1B[1;32m"                // Green terminal font colour
#define CLEAR_STRING        "\033[H\033[2J\033[3J"      // String used to clear terminal

#define clear_terminal()    printf(CLEAR_STRING);       // Function to clear the terminal

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
/**
 * Returns a win_size struct with information about the terminal window size.
 * 
 * @returns structure with terminal window size
 */
win_size get_win_size();

#endif //RENDER_H_