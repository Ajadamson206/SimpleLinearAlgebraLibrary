#ifndef CONVERSIONS
#define CONVERSIONS

#include "vector.h"
#include "matrix.h"
#include "stdint.h"

/**
 * @brief Copy the given vector into a malloced n x 1 matrix. The return matrix
 * must be freed by the user by calling matrix_delete.
 * @param vector (Vector*) The vector which is going to be copied into
 * the matrix
 * @return The malloced n x 1 matrix. Note that the returned matrix must by freed by the
 * user by calling matrix_delete.
*/
extern Matrix* vector_copy_to_matrix(Vector* vector); 

/**
 * @brief Convert a row from a Matrix to a Vector
 * @param matrix (Matrix*) The matrix which the row will be converted to a vector
 * @param row (uint32_t) The number of which row will be converted to a vector. 
 * Keep in mind that the rows start at zero.
 * @return Vector* to a copy of the specified row's data. The returned Vector*
 * will be malloced and will rely on the user to call vector_destroy to remove it.
 * NULL will be returned if the matrix is not defined on the specified row
*/
extern Vector* matrix_row_to_vector(Matrix* matrix, uint32_t row);

/**
 * @brief Convert a column from a Matrix to a Vector
 * @param matrix (Matrix*) The matrix which the column will be converted to a vector
 * @param colunm (uint32_t) The column index which will be converted to a vector.
 * Keep in mind that the rows start at zero.
 * @return Vector* to a copy of the specified row's data. The returned Vector*
 * will be malloced and will rely on the user to call vector_destroy to remove it.
 * NULL will be returnde if the matrix is not defined on the specified column.
*/
extern Vector* matrix_column_to_vector(Matrix* matrix, uint32_t column);

#endif