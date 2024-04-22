#include "vector.h"
#include <math.h>

extern Vector* vector_addition(Vector* vector_A, Vector* vector_B);
extern void vector_added_to(Vector* vector_A, Vector* vector_B);
extern Vector* vector_subtraction(Vector* vector_A, Vector* vector_B);
extern void vector_subtracted_from(Vector* vector_A, Vector* vector_B);
extern double vector_dot_product(Vector* vector_A, Vector* vector_B);
extern Vector* vector_scaling(Vector* vector, double scalar);
extern void vector_scale(Vector* vector, double scalar);
extern Vector* vector_normal_vector(Vector* vector_A);
extern void vector_normalize(Vector* vector_A);