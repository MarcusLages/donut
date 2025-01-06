#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // TODO: change everything to double

#include "render.h"
#include "donut.h"

void display_torus() {
    win_size window = get_win_size();
    char **output = initialize_framebuffer(window);

    // calculate_torus_in_rotation(output, window, 0.5, 0.5);
    calculate_plane_in_rotation(output, window, 0.0, M_PI/4);
    render_frame(output, window);

    free_framebuffer(output, window);
}

void calculate_torus_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {
    
    
}

void calculate_plane_in_rotation(char **output, const win_size window,
                                const float x_rotation_rad, const float z_rotation_rad) {

    const float min_depth = 5;
    const float window_ratio = 0.65f;     // Displayable window to terminal ratio
    const float max_plane_rotation_rad = M_PI_2; //  π/2 or 45º
    
    // Formula used to find the projection ratio from the real object to the screen.
    // This formula uses the fact that a plane rotated 45deg to any size will produce the max projection
    // of the plane on the x and y axis. This max length is then projected to fit exactly
    // half the screen height.
    const float projection_ratio = (min_depth * window_ratio * window.height) / (2 * PLANE_SIZE * sin(max_plane_rotation_rad));

    // Calculates cossines and sines to avoid frequent calculations.
    const float cos_x_rot = cos(x_rotation_rad), sin_x_rot = sin(x_rotation_rad);
    const float cos_z_rot = cos(z_rotation_rad), sin_z_rot = sin(z_rotation_rad);

    for(float i = -PLANE_SIZE; i < PLANE_SIZE ; i += SPACE_GAP) {
        for(float j = -PLANE_SIZE; j < PLANE_SIZE; j += SPACE_GAP) {
            // k to complete the ijk coordinate system.
            // Using 0 because we are using a plane, so we don't need depth
            float k = 0;

            // Applying two matrix multiplications to rotate the plane on the x and z axis.
            float x =  i * cos_z_rot             + j * sin_z_rot;
            float y = -i * cos_x_rot * sin_z_rot + j * cos_x_rot * cos_z_rot + k * sin_x_rot;
            float z =  i * sin_x_rot * sin_z_rot - j * sin_x_rot * cos_z_rot + k * cos_x_rot;

            // Moves to the center of the screen then calculates the projection of the shape (plane)
            // into the screen using the depth (z) considering the min_depth as 0.
            int x_projection = ((float) window.width/2) + (x * projection_ratio) / (z + min_depth);
            int y_projection = ((float) window.height/2) + (y * projection_ratio) / (z + min_depth);
            
            // Only writes character to buffer if it can be printed on the screen (if it's in boundaries
            // of the buffer)
            if(x_projection >= 0 && x_projection < window.width &&
               y_projection >= 0 && y_projection < window.height)
                output[x_projection][y_projection] = '*';
        }    
    }
}