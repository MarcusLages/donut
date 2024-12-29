#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "donut.h"

void display_torus() {
    render_frame(1, 1);
}

void render_frame(const float x_rotation_rad, const float z_rotation_rad) {
    clear_terminal();
    // printf("hey\n");
    
    win_size window = get_win_size();
    printf("(%zu, %zu)", window.width, window.height);
}