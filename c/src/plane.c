#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/vector.h"
#include "../include/render.h"
#include "../include/plane.h"

// TODO: think on how to use signal.h to change the screen buffer when the terminal resizes.
void display_plane() {
    const win_size window = get_win_size();
    char **output = initialize_framebuffer(window);
    float rotation_rad = 0.0f;

    handle_cursor();

    while(true) {
        calculate_plane_in_rotation(output, window, rotation_rad, rotation_rad);
        render_frame(output, window);

        rotation_rad += ROTATION_STEP_RAD;
        if(rotation_rad >= FULL_ROTATION) rotation_rad -= FULL_ROTATION;

        sleep_ms(fps_to_ms(ANIMATION_FPS));
    }

    free_framebuffer(output, window);
}

void calculate_plane_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {
    const float projection_ratio = calculate_plane_projection_ratio(window);

    for(float i = -PLANE_SIZE; i < PLANE_SIZE ; i += SPACE_GAP) {
        for(float j = -PLANE_SIZE; j < PLANE_SIZE; j += SPACE_GAP) {
            // Using 0 because we are using a plane, so we don't need depth
            Vector3 vector_init = {i, j, 0};
            Vector3 vector_rotated = matrix_rotation(vector_init, x_rotation_rad, z_rotation_rad);

            // Moves to the center of the screen then calculates the projection of the shape (plane)
            // into the screen using the depth (z) considering the MIN_DEPTH as 0.
            // TODO: isolate into function
            int x_projection = ((float) window.width/2) + (vector_rotated.x * projection_ratio) / (vector_rotated.z + MIN_DEPTH);
            int y_projection = ((float) window.height/2) + (vector_rotated.y * projection_ratio) / (vector_rotated.z + MIN_DEPTH);
            
            // Only writes character to buffer if it can be printed on the screen (if it's in boundaries
            // of the buffer)
            // TODO: isolate into function
            if(x_projection >= 0 && x_projection < window.width &&
               y_projection >= 0 && y_projection < window.height)
                output[x_projection][y_projection] = '*';
        }    
    }
}

float calculate_plane_projection_ratio(const win_size window) {
    // Formula used to find the projection ratio from the real object to the screen.
    // This formula uses the fact that a plane rotated 45deg(MAX_PLANE_ROTATION_RAD) to any size will produce the
    // max projection of the plane on the x and y axis. This max length is then projected to fit into a space
    // related to the window_ratio.
    return (MIN_DEPTH * WINDOW_RATIO * window.height) / (2 * PLANE_SIZE * sin(MAX_PLANE_ROTATION_RAD));
}