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