#ifndef MATRIX
#define MATRIX

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

static int merror = 0;

typedef struct Matrix {
    uint32_t _n;
    uint32_t _m;
    double** _data;
} Matrix;

/**
 * @brief Create a new matrix and fill it with values
 * @param n (uint32_t) The number of rows the matrix has
 * @param m (uint32_t) The number of columns each row has
 * @param va_args (double) The values that are going to be in the matrix
 * The number of inputs in the parameters must equal n x m.
 * @return Malloced Matrix* that is storing the matrix information. Relies on the
 * user to call matrix_delete. 
*/
extern Matrix* matrix_create_fill(uint32_t n, uint32_t m, ...);
extern Matrix* matrix_create_empty(uint32_t n, uint32_t m);
extern Matrix* matrix_create_identity_matrix(uint32_t R);
extern void matrix_set(Matrix* matrix, uint32_t n, uint32_t m, double value);
extern void matrix_reset_pattern(Matrix* matrix, ...);
extern void matrix_set_start_pattern(Matrix* matrix, uint32_t start_row, uint32_t start_column, uint32_t count, ...);
extern void matrix_print(Matrix* matrix);
extern void matrix_delete(Matrix* matrix);
extern double matrix_get_data(Matrix* matrix, uint32_t row, uint32_t column);
extern double matrix_get_row_length(Matrix* matrix);
extern double matrix_get_column_length(Matrix* matrix);
extern bool matrix_equals(Matrix* matrix_A, Matrix* matrix_B);

#endif