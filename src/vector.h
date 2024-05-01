#ifndef VECTOR
#define VECTOR

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"

typedef struct vector {
    uint32_t _n;
    double* _data;
} Vector;

/**
 * @brief Create a vector of length n
 * @param n (uint32_t) The length of the new vector
 * @param va_args (double) The numbers that are going to be added to fill
 * the vector. There must be the same amount of numbers as the length specified
 * under n.
 * @return Vector* containing a length of n and filled with the numbers
 * passed into the arguments. Note: The Vector* is malloced and the user
 * must call vector_destroy to free the vector.
*/
extern Vector* vector_create_fill(uint32_t n, ...);

/**
 * @brief Create a blank vector of length n
 * @param n (uint32_t) The length the vector is going to be
 * @return A Vector* that contains an empty vector of length n. The 
 * vector is malloced and relies on the user to call vector_destroy
*/
extern Vector* vector_create_empty(uint32_t n);

/**
 * @brief Get the length of the current vector
 * @param vector (Vector*) The vector who's length is being determined
 * @return The length (uint32_t) of the vector
*/
inline uint32_t vector_get_length(Vector* vector) {
    return vector->_n;
};

/**
 * @brief Access a particular element of the vector
 * @param vector (Vector*) The vector that is going to be accessed
 * @param index (uint32_t) The index of the element
 * @return The element at specified index
*/
inline double vector_access(Vector* vector, uint32_t index) {
    return vector->_data[index];
};

/**
 * @brief Compare the elements of the two vectors to see if they are equal
 * @param vector_A (Vector*) The first vector to be compared
 * @param vector_B (Vector*) The second vector to be compared
 * @return TRUE if every element of vector_A equals vector_B
 * FALSE if otherwise
*/
extern bool vector_equals(Vector* vector_A, Vector* vector_B);

/**
 * @brief Free the given vector from memory
 * @param vector (Vector*) The vector which is going to freed from memory
*/
extern void vector_destroy(Vector* vector);

#endif