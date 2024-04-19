#ifndef MATRIXOPERATIONS
#define MATRIXOPERATIONS

#include "matrix.h"

extern Matrix* matrix_scalar_multiplication(Matrix* scalar_matrix, double scalar);

extern Matrix* matrix_addition(Matrix* matrix_A, Matrix* matrix_B);

extern Matrix* matrix_subtraction(Matrix* matrix_A, Matrix* matrix_B);

extern Matrix* matrix_multiplication(Matrix* matrix_A, Matrix* matrix_B);

#endif