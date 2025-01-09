#ifndef VECTOR_H_
#define VECTOR_H_

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

#endif //VECTOR_H_