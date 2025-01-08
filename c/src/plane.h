#ifndef PLANE_H_
#define PLANE_H_

#define _USE_MATH_DEFINES   // For using PI

#include "terminal.h"

//* Math macros/constants
#define FULL_ROTATION               2*M_PI
#define PLANE_SIZE                  1
#define SPACE_GAP                   0.02
#define ROTATION_STEP_RAD           0.1

//* Function Prototypes
/**
 * Function used to display the rotating plane.
 */
void display_plane();

/**
 * Function used to display a single frame of a plane at a specific rotation
 * on the x and z axis.
 * 
 * @param x_rotation_rad degree of rotation of the torus/donut on the x axis in radians
 * @param y_rotation_rad degree of rotation of the torus/donut on the z axis in radians
 */
void calculate_plane_in_rotation(char **output, const win_size window,
                        const float x_rotation_rad, const float z_rotation_rad);

// TODO: document it
float calculate_plane_projection_ratio(const float min_depth, const float window_ratio, const float max_plane_rotation_rad,
            const win_size window);

#endif //PLANE_H_