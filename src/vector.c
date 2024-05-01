#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "matrix.h"

typedef struct vector {
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

bool vector_equals(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return false;

    for(int i = 0; i < vector_A->_n; i++) {
        if(vector_A->_data[i] != vector_B->_data[i])
            return false;
    }

    return true;
}

void vector_destroy(Vector* vector) {
    free(vector->_data);
    free(vector);
}