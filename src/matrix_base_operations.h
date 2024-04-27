#ifndef MATRIXOPERATIONS
#define MATRIXOPERATIONS

#include "matrix.h"

/**
 * @brief Multiply the matrix by a scalar, into a new matrix.
 * @param scalar_matrix (Matrix*) The matrix that is going to be scaled.
 * @param scalar (double) The scalar that the matrix is going to be scaled by.
 * @return The scaled matrix will return as a malloced Matrix* and will rely on the user to call free.
*/
extern Matrix* matrix_scalar_multiplication(Matrix* scalar_matrix, double scalar);

/**
 * @brief Add the contents of two matrices, into a new matrix. The matrixes must have the same n and m.
 * @param matrix_A (Matrix*) matrix A that is one of the matrixes being added.
 * @param matrix_B (Matrix*) matrix B that is being added to matrix A.
 * @return The sum matrix that will be returned as a malloced Matrix* and will rely on the user to call free,
 * NULL will be returned if the matrices are unable to be added
*/
extern Matrix* matrix_addition(Matrix* matrix_A, Matrix* matrix_B);

/**
 * @brief Subtract the contents of two matrices, into a new matrix. The matrixes must have the same dimensions.
 * @param matrix_A (Matrix*) matrix A that is that is going to be subtracted from.
 * @param matrix_B (Matrix*) matrix B that is doing the subtracting.
 * @return The difference matrix that will be returned as a malloced Matrix* and will rely on the user to call free,
 * NULL will be returned if the matrices are unable to be subtracted.
*/
extern Matrix* matrix_subtraction(Matrix* matrix_A, Matrix* matrix_B);

/**
 * @brief Multiply two matrices together. Matrix A's n must equal Matrix B's m.
 * @param matrix_A (Matrix*) matrix A that is going to be multipled by matrix B
 * @param matrix_B (Matrix*) matrix B that is going to multiply into matrix A
 * @return The product matrix that will be returned as a malloced Matrix* and will rely on the user to call free.
 * The matrix that is returned will have the same n as matrix A and the same m as matrix B.
 * NULL will be returned if the matrices cannot be multiplied
*/
extern Matrix* matrix_multiplication(Matrix* matrix_A, Matrix* matrix_B);

#endif