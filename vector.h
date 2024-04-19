#ifndef VECTOR
#define VECTOR

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector {
    uint32_t _n;
    double* _data;
} Vector;

extern Vector* vector_create_fill(uint32_t n, ...);
extern Vector* vector_create_empty(uint32_t n);

#endif