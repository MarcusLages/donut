#ifndef PLANE_H_
#define PLANE_H_

#define _USE_MATH_DEFINES   // For using PI

#include <math.h>
#include "terminal.h"

//* Math macros/constants
#define PLANE_SIZE                  1
#define SPACE_GAP                   0.02
#define ROTATION_STEP_RAD           0.1
#define FULL_ROTATION               2*M_PI
#define MAX_PLANE_ROTATION_RAD      M_PI_2  // π/2 or 45º
#define MIN_DEPTH                   5       // Closest possible depth that an object can be displayed on the screen
                                            // (the larger, the further away an object looks)
#define WINDOW_RATIO                0.65F   // Displayable window to terminal ratio (the closest to one, the closest
                                            // an object appears)

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

/**
 * Calculate the projection ratio of a plane in the available screen.
 * 
 * @param window    Structure containing the size of the window
 */
float calculate_plane_projection_ratio(const win_size window);

#endif //PLANE_H_