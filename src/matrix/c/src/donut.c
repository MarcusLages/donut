#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>   // TODO: change everything to double

#include "render.h"
#include "donut.h"

// TODO: think on how to use signal.h to change the screen buffer when the terminal resizes.
// TODO: animation on terminal in c
void display_torus() {
    win_size window = get_win_size();
    char **output = initialize_framebuffer(window);

    // calculate_torus_in_rotation(output, window, 0.5, 0.5);
    float rotation_rad = 0.0f;
    while(true) {
        calculate_plane_in_rotation(output, window, rotation_rad, rotation_rad);
        render_frame(output, window);

        rotation_rad += 0.1f;
        if(rotation_rad >= 2*M_PI) rotation_rad -= 2*M_PI;

        sleep_ms(1000.0f / 20.0f); // TODO: add MACROS and consts instead of magic numbers
    }

    free_framebuffer(output, window);
}

void calculate_torus_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {
    
    
}

void calculate_plane_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {
    // TODO: Might move all these constants out of the functions into a header file
    const float min_depth = 5;
    const float window_ratio = 0.65f;     // Displayable window to terminal ratio
    const float max_plane_rotation_rad = M_PI_2; //  π/2 or 45º
    
    // Formula used to find the projection ratio from the real object to the screen.
    // This formula uses the fact that a plane rotated 45deg to any size will produce the max projection
    // of the plane on the x and y axis. This max length is then projected to fit exactly
    // half the screen height.
    const float projection_ratio = (min_depth * window_ratio * window.height) / (2 * PLANE_SIZE * sin(max_plane_rotation_rad));

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

void matrix_rotation(const float i, const float j, const float k,
                     const float x_rotation_rad, const float z_rotation_rad,
                     float *x_rotated, float *y_rotated, float *z_rotated) {
                        
    // Calculates cossines and sines to avoid frequent calculations.
    const float cos_x_rot = cos(x_rotation_rad), sin_x_rot = sin(x_rotation_rad);
    const float cos_z_rot = cos(z_rotation_rad), sin_z_rot = sin(z_rotation_rad);

    *x_rotated =  i * cos_z_rot             + j * sin_z_rot;
    *y_rotated = -i * cos_x_rot * sin_z_rot + j * cos_x_rot * cos_z_rot + k * sin_x_rot;
    *z_rotated =  i * sin_x_rot * sin_z_rot - j * sin_x_rot * cos_z_rot + k * cos_x_rot;
}