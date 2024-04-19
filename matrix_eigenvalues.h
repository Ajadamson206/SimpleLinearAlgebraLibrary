#ifndef EIGEN
#define EIGEN

#include "matrix.h"
#include <math.h>
#include <stdlib.h>
#include <complex.h>

extern double complex* matrix_2x2_find_eigenvalues(Matrix* matrix);
extern double complex* matrix_3x3_find_eigenvalues(Matrix* matrix);

#endif