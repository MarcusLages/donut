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
    
}