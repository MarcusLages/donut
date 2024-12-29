#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "donut.h"

/**
 * Programs entry point and that does all the logic.
 */
int main() {
    display_torus();
    return EXIT_SUCCESS;
}

void display_torus() {
    render_frame(1, 1);
}

void render_frame(const float x_rotation_rad, const float z_rotation_rad) {
    clear_terminal();
    printf("hey\n");

}