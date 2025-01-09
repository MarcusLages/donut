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