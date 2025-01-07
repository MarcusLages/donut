#ifndef DONUT_H
#define DONUT_H

#include "render.h"

//* Math macros/constants
#define CIRCUMFERENCE_SLICE_SPACING 0.07  // Gap between angle slices inside the circumference
#define CIRCUMFERENCE_GAP_SPACING   0.02  // Gap between circumferences that generate a torus
#define TORUS_CYLINDER_RADIUS       1
#define TORUS_RADIUS                2

#define PLANE_SIZE                  1
#define SPACE_GAP                   0.02

 //* Function Prototypes
 
/**
 * Function used to display the torus/donut.
 */
void display_torus();

/**
 * Function used to display a single frame of the torus/donut at a specific rotation
 * on the x and z axis.
 * 
 * @param x_rotation_rad degree of rotation of the torus/donut on the x axis in radians
 * @param y_rotation_rad degree of rotation of the torus/donut on the z axis in radians
 */
void calculate_torus_in_rotation(char **output, const win_size window,
                        const float x_rotation_rad, const float z_rotation_rad);

/**
 * Function used to display a single frame of a plane at a specific rotation
 * on the x and z axis.
 * 
 * @param x_rotation_rad degree of rotation of the torus/donut on the x axis in radians
 * @param y_rotation_rad degree of rotation of the torus/donut on the z axis in radians
 */
void calculate_plane_in_rotation(char **output, const win_size window,
                        const float x_rotation_rad, const float z_rotation_rad);

void matrix_rotation(const float i, const float j, const float k,
                     const float x_rotation_rad, const float z_rotation_rad,
                     float *x_rotated, float *y_rotated, float *z_rotated);

 #endif // !DONUT_H
