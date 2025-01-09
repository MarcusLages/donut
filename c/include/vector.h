#ifndef VECTOR_H_
#define VECTOR_H_

// TODO: Vector3 structure
/**
 * Rotates a 3D vector v over the x and z axis using matrix multiplication
 * with rotation matrices over those axis.
 * 
 * @param i                 Component of vector on the x-axis
 * @param j                 Component of vector on the y-axis
 * @param k                 Component of vector on the z-axis
 * @param x_rotation_rad    Rotation of the vector on the x axis
 * @param z_rotation_rad    Rotation of the vector on the z axis
 * @param i_rotated         Rotated component of vector on the x-axis (output)
 * @param j_rotated         Rotated component of vector on the y-axis (output)
 * @param k_rotated         Rotated component of vector on the z-axis (output)
 */
void matrix_rotation(const float i, const float j, const float k,
                     const float x_rotation_rad, const float z_rotation_rad,
                     float *i_rotated, float *j_rotated, float *k_rotated);

#endif //VECTOR_H_