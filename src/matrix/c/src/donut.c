#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "donut.h"

void display_torus() {
    win_size window = get_win_size();
    char **output = initialize_framebuffer(window);

    render_frame(output, window);

    free_framebuffer(output, window);
}