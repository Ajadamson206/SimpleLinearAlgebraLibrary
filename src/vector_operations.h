#include "vector.h"
#include <math.h>

/**
 * @brief Add vectors together and create a new vector that is the sum vector
 * @param vector_A (Vector*) The first vector that is being added
 * @param vector_B (Vector*) The second vector that is being added
 * @return The sum vector as a Vector* that contains the sum of each element
 * NULL will be returned if the vectors could not be added
*/
extern Vector* vector_addition(Vector* vector_A, Vector* vector_B);

/**
 * @brief Add vector B into vector A. If the vectors cannot be added
 * vector A will remain the same
 * @param vector_A (Vector*) The vector that vector B is going to be added to
 * @param vector_B (Vector*) The vector that is going to be added to vector A
*/
extern void vector_added_to(Vector* vector_A, Vector* vector_B);

/**
 * @brief Subtract vector B from vector A and put the difference into a new vector
 * @param vector_A (Vector*) The first vector that is going to be subtracted from
 * @param vector_B (Vector*) The vector that is going to subtract A
 * @return The difference vector as a Vector* that contains the difference between
 * vector A and vector B. The new vector will be malloced and relies on the user to call vector_destroy.
 * NULL will be returned if the vectors could not be added
*/
extern Vector* vector_subtraction(Vector* vector_A, Vector* vector_B);

/**
 * @brief Subtract vector B from A, updating the difference in A. If the vectors are not able to be subtracted
 * vector A will remain the same.
 * @param vector_A (Vector*) The vector which the difference is being subtracted from
 * @param vector_B (vector*) The vector which is going to be used to subtract A
*/
extern void vector_subtracted_from(Vector* vector_A, Vector* vector_B);

/**
 * @brief Find the dot product between two vectors. If the vectors do not have a dot product then
 * the verror will be updated and 0 will be returned.
 * @param vector_A (Vector*) The first vector which will be used to find the dot product
 * @param vector_B (Vector*) THe second vector which will be used to find the dot product
 * @return The dot product between the two vectors
*/
extern double vector_dot_product(Vector* vector_A, Vector* vector_B);

/**
 * @brief Scale a vector by a certain scalar and store the result into a new vector
 * @param vector (Vector*) The vector that is going to be scaled
 * @param scalar (double) The scalar that is going to be multiply each element of the vector
 * @return The vector scaled by the scalar stored into a new malloced vector. The vector relies on the
 * user to call vector_destroy.
*/
extern Vector* vector_scaling(Vector* vector, double scalar);

/**
 * @brief Scale a vector by a scalar, updating the original vector
 * @param vector (Vector*) The vector that is going to be scaled
 * @param scalar (double) The scalar that is going to be multipy the vector
*/
extern void vector_scale(Vector* vector, double scalar);

/**
 * @brief Find the normal vector of the given vector and store it into a new vector
 * @param vector_A The vector which is going to be normalized
 * @return The normal vector of the given vector stored into a new malloced vector. 
 * The vector relies on the user to call vector_destroy. NULL will be returned if there is no 
 * normal vector
*/
extern Vector* vector_normal_vector(Vector* vector_A);

/**
 * @brief Normalize the given vector. If the vector cannot be normalized vector_A will remain 
 * the same
 * @param vector_B The vector that is going to be normalized
*/
extern void vector_normalize(Vector* vector_A);