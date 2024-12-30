#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "donut.h"

void display_torus() {
    win_size window = get_win_size();
    char **output = initialize_framebuffer(window);

    calculate_torus_in_rotation(output, window, 0.5, 0.5);
    render_frame(output, window);

    free_framebuffer(output, window);
}

void calculate_torus_in_rotation(char **output, const win_size window,
                        const float x_rotation_rad, const float z_rotation_rad) {
    // TODO: cos/sin
    const float cos_x_rad, cos_z_rad;
    const float sin_x_rad, sin_z_rad;

    float depth_buffer[window.width][window.height];
    for(int i = 0; i < window.width; i++)
        for(int j = 0; j < window.height; j++)
            depth_buffer[i][j] = 0.0f;

    // Loop that agoes around cross section of the circles that forms a torus
    // TODO: math library with PI
    for(float circle_section_rad = 0; circle_section_rad < 2*PI; circle_section_rad += CIRCUMFERENCE_SLICE_SPACING) {
        // TODO: cos/sin
        const float cos_circle_section, sin_circle_section; 

        // Loop that goes around the revolution of a torus (circumference shape)
        for(float torus_section_rad = 0; torus_section_rad < 2*PI; torus_section_rad += CIRCUMFERENCE_GAP_SPACING) {
            // TODO: cos/sin
            const float cos_torus_section, sin_torus_section;

            // TODO: rest of the logic

        }
    }
}