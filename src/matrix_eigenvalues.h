#ifndef EIGEN
#define EIGEN

#include "matrix.h"
#include <math.h>
#include <stdlib.h>
#include <complex.h>

/**
 * @brief A function which finds the eigenvalues of a 2x2 matrix by using the 
 * quadratic formula
 * @param matrix A matrix pointer that contains a 2x2 matrix
 * @returns NULL if the matrix is not a 2x2 Matrix
 * @returns A double complex pointer to a double complex array 
 * that contains two elements with the solutions
*/
extern double complex* matrix_2x2_find_eigenvalues(Matrix* matrix);

/**
 * @brief A function that find the value of a 3x3 matrix by use of the cubic 
 * formula
 * @param matrix A matrix pointer that contains a 3x3 matrix
 * @returns NULL if the matrix is not 3x3
 * @returns A double complex pointer to a double complex array with 3 elements
 * each containing a different eigenvalue
*/
extern double complex* matrix_3x3_find_eigenvalues(Matrix* matrix);

#endif