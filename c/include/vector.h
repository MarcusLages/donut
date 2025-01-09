#ifndef VECTOR_H_
#define VECTOR_H_

#include "terminal.h"

/**
 * Structure that represents a vector in 2 dimensions,
 * or a point in 2 dimensions. 
 */
typedef struct Vector2 {
    float x;    // x component of a vector (width)
    float y;    // y component of a vector (height)
} Vector2;

/**
 * Structure that represents a vector in 3 dimensions,
 * or a point in 3 dimensions. 
 */
typedef struct Vector3 {
    float x;    // x component of a vector (width)
    float y;    // y component of a vector (height)
    float z;    // z component of a vector (depth)
} Vector3;

/**
 * Rotates a 3D vector over the x and z axis using matrix multiplication
 * with rotation matrices over those axis.
 * 
 * @param vector            Vector to be rotated
 * @param x_rotation_rad    Rotation of the vector on the x axis
 * @param z_rotation_rad    Rotation of the vector on the z axis
 * @return                  Rotated vector over both angles
 */
Vector3 matrix_rotation(const Vector3 vector, float x_rotation_rad, const float z_rotation_rad);

/**
 * Calculates the projection of a 3D vector on the screen using a
 * projection ratio to fit in the screen and minimum depth that the
 * projection will be shown.
 * 
 * @param vector            3D vector to be projected
 * @param window            Size of the window where the vector will be
 *                          projected
 * @param projection_ratio  How much of the screen will the projection cover
 * @param min_depth         Minimum distance the shape can be projected to
 *                          in the screen
 * @return                  2D vector representing the projection of
 *                          the 3D vector on the screen
 */
Vector2 project_to_window(const Vector3 vector, const win_size window,
                          const float projection_ratio, const float min_depth);

#endif //VECTOR_H_