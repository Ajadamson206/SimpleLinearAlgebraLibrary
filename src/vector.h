#ifndef VECTOR
#define VECTOR

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

typedef struct Vector {
    uint32_t _n;
    double* _data;
} Vector;

extern Vector* vector_create_fill(uint32_t n, ...);
extern Vector* vector_create_empty(uint32_t n);
extern inline uint32_t vector_get_length(Vector* vector);
extern inline double vector_access(Vector* vector, uint32_t index);
extern bool vector_equals(Vector* vector_A, Vector* vector_B);
extern Matrix* vector_copy_to_matrix(Vector* vector); 

#endif