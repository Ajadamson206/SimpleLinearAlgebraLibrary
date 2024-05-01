#include "matrix.h"
#include <stdint.h>
#include "vector.h"
#include <string.h>

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

Matrix* vector_copy_to_matrix(Vector* vector) {
    Matrix* matrix = malloc(sizeof(*matrix));
    matrix->_m = 1;
    matrix->_n = vector->_n;
    matrix->_data = malloc(sizeof(double*));
    memcpy(matrix->_data[0], vector->_data, vector->_n);
    
    return matrix;
}