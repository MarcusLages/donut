#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdio.h>

//* Macros and constants
#define SECOND_MS               1000.0
#define SECOND_NS               1000000.0

// Strings that change the behaviour of the terminal when printed.
#define FONT_COLOUR_DEFAULT     "\x1B[0m"
#define FONT_COLOUR_GREEN       "\x1B[1;32m"
#define CLEAR_TERMINAL_STRING   "\033[H\033[2J\033[3J"
#define HIDE_CURSOR_STRING      "\033[?25l"
#define SHOW_CURSOR_STRING      "\033[?25h"

#define clear_terminal()        printf(CLEAR_TERMINAL_STRING);
#define hide_cursor()           printf(HIDE_CURSOR_STRING);
#define show_cursor()           printf(SHOW_CURSOR_STRING);

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
 * Sleeps the main thread for the given amount of milliseconds.
 * 
 * @param milliseconds amount of milliseconds the thread should wait
 */
void sleep_ms(const size_t milliseconds);

/**
 * Handles interruption of the program.
 * 
 * @param signal_code Interruption signal code (@unused)
 */
void handle_interruption(const int signal_code);

/**
 * Handle cursor handling on the program, such as hiding it on start
 * and showing it back once the program finishes.
 */
void handle_cursor();

#endif //TERMINAL_H_