#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <unistd.h>

//* Rendering macros/constants
#define SECOND_MS               1000.0

// Strings that change the behaviour of the terminal when printed.
#define FONT_COLOUR_DEFAULT     "\x1B[0m"
#define FONT_COLOUR_GREEN       "\x1B[1;32m"
#define CLEAR_TERMINAL_STRING   "\033[H\033[2J\033[3J"
#define HIDE_CURSOR_STRING      "\033[?25l"
#define SHOW_CURSOR_STRING      "\033[?25h"

#define clear_terminal()        printf(CLEAR_TERMINAL_STRING);
#define hide_cursor()           printf(HIDE_CURSOR_STRING);
#define show_cursor()           printf(SHOW_CURSOR_STRING);

#define EMPTY_PIXEL             ' '
#define ANIMATION_FPS           40

/**
 * Macro that calculates the amount of time a thread should sleep to
 * provide the given fps.
 * 
 * @param fps   FPS wanted
 * @return      Thread sleep delay in milliseconds
 */
#define fps_to_ms(fps)          SECOND_MS / fps

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
 * @return structure with terminal window size
 */
win_size get_win_size();

/**
 * Initializes framebuffer for printing characters on the screen.
 * 
 * @param window    win_size structure with the size of the window that the program
 *                  will be displayed on
 * @return 2D char framebuffer initialized as empty
 */
char ** initialize_framebuffer(const win_size window);

/**
 * Deallocates memory from framebuffer.
 * 
 * @param buffer    2D framebuffer to be deallocated
 * @param window    measures of the buffer
 */
void free_framebuffer(char **buffer, const win_size window);

/**
 * Renders a frame based on the output framebuffer.
 * 
 * @param output    2D framebuffer to be rendered
 * @param window    measure of the buffer and window
 */
void render_frame(char **output, const win_size window);

/**
 * Sleeps the main thread for the given amount of milliseconds.
 * 
 * @param milliseconds amount of milliseconds the thread should wait
 */
void sleep_ms(const size_t milliseconds);

#endif // !RENDER_H_