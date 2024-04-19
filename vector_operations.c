#include "vector.h"

Vector* vector_addition(Vector* vector_A, Vector* vector_B) {
    if(vector_A->_n != vector_B->_n)
        return NULL;

    Vector* sum_vector = vector_create_empty(vector_A->_n);
    for(int i = 0; i < vector_A->_n; i++) {
        sum_vector->_data[i] = vector_A->_data[i] + vector_B->_data[i];
    }

    return sum_vector;
}