#include <math.h>
#include "../include/vector.h"

void matrix_rotation(const float i, const float j, const float k,
                     const float x_rotation_rad, const float z_rotation_rad,
                     float *i_rotated, float *j_rotated, float *k_rotated) {
                        
    // Calculates cossines and sines to avoid frequent calculations.
    const float cos_x_rot = cos(x_rotation_rad), sin_x_rot = sin(x_rotation_rad);
    const float cos_z_rot = cos(z_rotation_rad), sin_z_rot = sin(z_rotation_rad);

    // Applying rotation over the x and z axis to vector ijk using matrix multiplication of the rotation
    // matrices that represent the rotations over the x and z axis.
    *i_rotated =  i * cos_z_rot             + j * sin_z_rot;
    *j_rotated = -i * cos_x_rot * sin_z_rot + j * cos_x_rot * cos_z_rot + k * sin_x_rot;
    *k_rotated =  i * sin_x_rot * sin_z_rot - j * sin_x_rot * cos_z_rot + k * cos_x_rot;
}