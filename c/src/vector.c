#include <math.h>
#include "../include/vector.h"

Vector3 matrix_rotation(const Vector3 vector, float x_rotation_rad, const float z_rotation_rad) {
    // Calculates cossines and sines to avoid frequent calculations.
    const float cos_x_rot = cos(x_rotation_rad), sin_x_rot = sin(x_rotation_rad);
    const float cos_z_rot = cos(z_rotation_rad), sin_z_rot = sin(z_rotation_rad);

    // Applying rotation over the x and z axis to vector ijk using matrix multiplication of the rotation
    // matrices that represent the rotations over the x and z axis.
    return (Vector3) {
        .x =  vector.x * cos_z_rot             + vector.y * sin_z_rot,
        .y = -vector.x * cos_x_rot * sin_z_rot + vector.y * cos_x_rot * cos_z_rot + vector.z * sin_x_rot,
        .z =  vector.x * sin_x_rot * sin_z_rot - vector.y * sin_x_rot * cos_z_rot + vector.z * cos_x_rot
    };
}

Vector2 project_to_window(const Vector3 vector, const win_size window,
                          const float projection_ratio, const float min_depth) {
    // Moves to the center of the screen then calculates the projection of the shape (plane)
    // into the screen using the depth (z) considering the MIN_DEPTH as 0.
    return (Vector2) {
        .x = ((float) window.width / 2) + (vector.x * projection_ratio) / (vector.z + min_depth),
        .y = ((float) window.height / 2) + (vector.y * projection_ratio) / (vector.z + min_depth)
    };
}