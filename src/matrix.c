#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "vector.h"

static int merror = 0;

typedef struct Matrix {
    uint32_t _n;
    uint32_t _m;
    double** _data;
} Matrix;

Matrix* matrix_create_fill(uint32_t n, uint32_t m, ...) {
    va_list args;
    va_start(args, m);

    double** matrix_data = malloc(n * sizeof(double*));

    for(int row = 0; row < n; row++) {
        matrix_data[row] = malloc(m * sizeof(double));
        for(int column = 0; column < m; column++) {
            matrix_data[row][column] = va_arg(args, double);
         }
    }

    Matrix* matrix = malloc(sizeof(*matrix));
    matrix->_m = m;
    matrix->_n = n;
    matrix->_data = matrix_data;

    va_end(args);

    return matrix;
}

Matrix* matrix_create_empty(uint32_t n, uint32_t m) {
    double** matrix_data = malloc(n * sizeof(double*));

    for(int row = 0; row < n; row++) {
        matrix_data[row] = calloc(m, sizeof(int));
    }

    Matrix* matrix = malloc(sizeof(*matrix));
    matrix->_m = m;
    matrix->_n = n;
    matrix->_data = matrix_data;

    return matrix;
}

Matrix* matrix_create_identity_matrix(uint32_t R) {
    double** matrix_data = malloc(R * sizeof(double*));

    for(int row = 0; row < R; row++) {
        matrix_data[row] = calloc(R, sizeof(int));
        matrix_data[row][row] = 1;        
    }

    Matrix* matrix = malloc(sizeof(*matrix));
    matrix->_m = R;
    matrix->_n = R;
    matrix->_data = matrix_data;

    return matrix;
}

void matrix_set(Matrix* matrix, uint32_t n, uint32_t m, double value) {
    if((n >= matrix->_n) || (m >= matrix->_m)){
        return;
    }

    matrix->_data[n][m] = value;
}

void matrix_reset_pattern(Matrix* matrix, ...) {
    va_list args;
    va_start(args, matrix);

    for(int row = 0; row < matrix->_n; row++) {
        for(int column = 0; column < matrix->_m; column++) {
            matrix->_data[row][column] = va_arg(args, double);
        }
    }
}

void matrix_set_start_pattern(Matrix* matrix, uint32_t start_row, uint32_t start_column, uint32_t count, ...) {
    va_list args;
    va_start(args, count);

    if((matrix->_n*matrix->_m) < count) {
        return;
    }

    for(int column = column; column < matrix->_m; column++) {
        matrix->_data[start_row][column] = va_arg(args, double);
    }

    start_row++;
    for(int row = start_row; row < matrix->_n; row++) {
        for(int column = 0; column < matrix->_m; column++) {
            matrix->_data[row][column] = va_arg(args, double);
        }
    }
}

void matrix_print(Matrix* matrix) {
    printf("{\n");
    for(int row = 0; row < matrix->_n; row++) {
        for(int column = 0; column < matrix->_m; column++) {
            printf("%f, ", matrix->_data[row][column]);
        }
        printf("\n");
    }
    printf("}\n");
}

void matrix_delete(Matrix* matrix) {
    for(int row = 0; row < matrix->_n; row++) {
        free(matrix->_data[row]);
    }

    free(matrix->_data);
    free(matrix);
}

bool matrix_equals(Matrix* matrix_A, Matrix* matrix_B) {
    if(matrix_A->_m != matrix_B->_m || matrix_A->_n != matrix_B->_n)
        return false;
    

    for(int n = 0; n < matrix_A->_n; n++) {
        for(int m = 0; m < matrix_A->_m; m++) {
            if(matrix_A->_data[n][m] != matrix_B->_data[n][m])
                return false;
        }
    }

    return true;
}

Matrix* matrix_copy(Matrix* matrix) {
    Matrix* copied_matrix = matrix_create_empty(matrix->_n, matrix->_m);

    for(int row = 0; row < matrix->_n; row++) {
        for(int column = 0; column < matrix->_m; column++) {
            copied_matrix->_data[row][column] = matrix->_data[row][column];
        }
    }

    return copied_matrix;
}

Vector* matrix_row_to_vector(Matrix* matrix, uint32_t row) {
    if(row >= matrix->_n)
        return NULL;

    Vector* vector = vector_create_empty(matrix->_m);

    for(int column = 0; column < matrix->_m; column++) {
        vector->_data[column] = matrix->_data[row][column];
    }

    return vector;
}

Vector* matrix_column_to_vector(Matrix* matrix, uint32_t column) {
    if(column >= matrix->_m)
        return NULL;

    Vector* vector = vector_create_empty(matrix->_n);

    for(int row = 0; row < matrix->_n; row++) {
        vector->_data[row] = matrix->_data[column][row];
    }

    return vector;
}