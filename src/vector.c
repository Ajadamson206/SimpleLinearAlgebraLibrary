#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "matrix.h"

typedef struct Vector {
    uint32_t _n;
    double* _data;
} Vector;

Vector* vector_create_fill(uint32_t n, ...) {
    va_list args;
    va_start(args, n);

    double* vector_data = malloc(n * sizeof(double));

    for(int i = 0; i < n; i++) {
        vector_data[i] = va_arg(args, double);
    }

    Vector* vector = malloc(sizeof(*vector));
    vector->_n = n;
    vector->_data = vector_data;

    return vector;
}

Vector* vector_create_empty(uint32_t n) {
    double* vector_data = calloc(n, sizeof(*vector_data));

    Vector* vector = malloc(n * sizeof(*vector));
    vector->_n = n;
    vector->_data = vector_data;

    return vector;
}

uint32_t vector_get_length(Vector* vector) {
    return vector->_n;
}

double vector_access(Vector* vector, uint32_t index) {
    return vector->_data[index];
}

bool vector_equals(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return false;

    for(int i = 0; i < vector_A->_n; i++) {
        if(vector_A->_data[i] != vector_B->_data[i])
            return false;
    }

    return true;
}

Matrix* vector_copy_to_matrix(Vector* vector) {
    Matrix* matrix = malloc(sizeof(*matrix));
    matrix->_m = 1;
    matrix->_n = vector->_n;
    matrix->_data = malloc(sizeof(double*));
    memcpy(matrix->_data[0], vector->_data, vector->_n);
    
    return matrix;
}

void vector_destroy(Vector* vector) {
    free(vector->_data);
    free(vector);
}