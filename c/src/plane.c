#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

#include "vector.h"
#include "render.h"
#include "plane.h"

// TODO: think on how to use signal.h to change the screen buffer when the terminal resizes.
// TODO: animation on terminal in c
void display_plane() {
    const win_size window = get_win_size();
    char **output = initialize_framebuffer(window);
    float rotation_rad = 0.0f;

    // TODO: Cursor functions into one function.
    // TODO: Add things so any key the user presses, closes the program.
    signal(SIGINT, handle_interruption);
    hide_cursor();

    while(true) {
        calculate_plane_in_rotation(output, window, rotation_rad, rotation_rad);
        render_frame(output, window);

        rotation_rad += ROTATION_STEP_RAD;
        if(rotation_rad >= FULL_ROTATION) rotation_rad -= FULL_ROTATION;

        sleep_ms(fps_to_ms(ANIMATION_FPS));
    }

    free_framebuffer(output, window);
    show_cursor();
}

void calculate_plane_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {
    // TODO: Might move all these constants out of the functions into a header file
    const float min_depth = 5;
    const float window_ratio = 0.65f;            // Displayable window to terminal ratio
    const float max_plane_rotation_rad = M_PI_2; //  π/2 or 45º
    
    const float projection_ratio = calculate_plane_projection_ratio(min_depth, window_ratio, max_plane_rotation_rad, window);

    for(float i = -PLANE_SIZE; i < PLANE_SIZE ; i += SPACE_GAP) {
        for(float j = -PLANE_SIZE; j < PLANE_SIZE; j += SPACE_GAP) {
            // k to complete the ijk coordinate system.
            // Using 0 because we are using a plane, so we don't need depth
            float k = 0;

            float x_rotated, y_rotated, z_rotated;
            matrix_rotation(i, j, k, x_rotation_rad, z_rotation_rad, &x_rotated, &y_rotated, &z_rotated);

            // Moves to the center of the screen then calculates the projection of the shape (plane)
            // into the screen using the depth (z) considering the min_depth as 0.
            int x_projection = ((float) window.width/2) + (x_rotated * projection_ratio) / (z_rotated + min_depth);
            int y_projection = ((float) window.height/2) + (y_rotated * projection_ratio) / (z_rotated + min_depth);
            
            // Only writes character to buffer if it can be printed on the screen (if it's in boundaries
            // of the buffer)
            if(x_projection >= 0 && x_projection < window.width &&
               y_projection >= 0 && y_projection < window.height)
                output[x_projection][y_projection] = '*';
        }    
    }
}

// TODO: remove max_plane_rotation_rad from argument and use a macro for it instead
float calculate_plane_projection_ratio(const float min_depth, const float window_ratio, const float max_plane_rotation_rad,
                                 const win_size window) {
    // Formula used to find the projection ratio from the real object to the screen.
    // This formula uses the fact that a plane rotated 45deg to any size will produce the max projection
    // of the plane on the x and y axis. This max length is then projected to fit into a space related to
    // the window_ratio.
    return (min_depth * window_ratio * window.height) / (2 * PLANE_SIZE * sin(max_plane_rotation_rad));
}