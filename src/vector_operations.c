#include "vector.h"
#include <math.h>

Vector* vector_addition(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return NULL;

    Vector* sum_vector = vector_create_empty(vector_A->_n);
    for(int i = 0; i < vector_A->_n; i++) {
        sum_vector->_data[i] = vector_A->_data[i] + vector_B->_data[i];
    }

    return sum_vector;
}

void vector_added_to(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return;

    for(int i = 0; i < vector_A->_n; i++) {
        vector_A->_data[i] += vector_B->_data[i];
    }
}

Vector* vector_subtraction(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n) 
        return NULL;
    
    Vector* difference_vector = vector_create_empty(vector_A->_n);
    for(int i = 0; i < vector_A->_n; i++) {
        difference_vector->_data[i] = vector_A->_data[i] - vector_B->_data[i];
    }

    return difference_vector;
}

void vector_subtracted_from(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return;

    for(int i = 0; i < vector_A->_n; i++) {
        vector_A->_data[i] -= vector_B->_data[i];
    }
}

double vector_dot_product(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return 0;

    double product = 0;
    for(int i = 0 ; i < vector_A->_n; i++) {
        product += vector_A->_data[i] * vector_B->_data[i];
    }
    return product;
}

Vector* vector_scaling(Vector* vector, double scalar) {
    Vector* scaled_vector = vector_create_empty(vector->_n);
    for(int i = 0; i < vector->_n; i++) {
        scaled_vector->_data[i] = scalar * vector->_data[i];
    }

    return scaled_vector;
}

void vector_scale(Vector* vector, double scalar) {
    for(int i = 0; i < vector->_n; i++) {
        vector->_data[i] *= scalar;
    }
}

Vector* vector_normal_vector(Vector* vector_A) {
    if(vector_A->_n == 0)
        return NULL;

    double c = 0;
    for(int i = 0; i < vector_A->_n; i++) {
        c += vector_A->_data[i] * vector_A->_data[i];
    }
    
    return vector_scaling(vector_A, sqrt(c));
}

void vector_normalize(Vector* vector_A) {
    if(vector_A->_n == 0)
        return;
    
    double c = 0;
    for(int i = 0; i < vector_A->_n; i++) {
        c += vector_A->_data[i] * vector_A->_data[i];
    }

    vector_scale(vector_A, sqrt(c));
}