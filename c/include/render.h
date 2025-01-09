#ifndef RENDER_H_
#define RENDER_H_

#include "terminal.h"

//* Rendering macros/constants
#define ANIMATION_FPS           40
#define EMPTY_PIXEL             ' '

/**
 * Macro that calculates the amount of time a thread should sleep to
 * provide the given fps.
 * 
 * @param fps   FPS wanted
 * @return      Thread sleep delay in milliseconds
 */
#define fps_to_ms(fps)          SECOND_MS / fps

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

#endif // !RENDER_H_