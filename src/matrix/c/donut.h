 #ifndef DONUT_H
 #define DONUT_H

//* Constants

#define CIRCLE_POINT_SPACING 0.07  // Gap between points inside the circumference
#define TORUS_CIRCLE_SPACING 0.02  // Gap between circumferences that generate a torus


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
void render_frame(const float x_rotation_rad, const float z_rotation_rad);

 #endif // !DONUT_H
