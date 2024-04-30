#include "matrix.h"
#include <complex.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


Matrix* matrix_scalar_multiplication(Matrix* scalar_matrix, double scalar) {
    double** matrix_data = malloc(scalar_matrix->_n * sizeof(double*));

    for(int row = 0; row < scalar_matrix->_n; row++) {
        matrix_data[row] = malloc(scalar_matrix->_m * sizeof(int));
        for(int column = 0; column < scalar_matrix->_m; column++) {
            matrix_data[row][column] = scalar * scalar_matrix->_data[row][column];
        }
    }

    Matrix* scaled_matrix = malloc(sizeof(*scaled_matrix));
    scaled_matrix->_m = scalar_matrix->_m;
    scaled_matrix->_n = scalar_matrix->_n;
    scaled_matrix->_data = matrix_data;

    return scaled_matrix;
}

Matrix* matrix_addition(Matrix* matrix_A, Matrix* matrix_B) {
    if((matrix_A->_m != matrix_B->_m) || (matrix_A->_n != matrix_B->_n)) {
        return NULL;
    }

    double** matrix_data = malloc(matrix_A->_n * sizeof(double*));

    for(int row = 0; row < matrix_A->_n; row++) {
        matrix_data[row] = malloc(matrix_A->_m * sizeof(int));
        for(int column = 0; column < matrix_A->_m; column++) {
            matrix_data[row][column] = matrix_A->_data[row][column] + matrix_B->_data[row][column];
        }
    }

    Matrix* sum_matrix = malloc(sizeof(*sum_matrix));
    sum_matrix->_m = matrix_A->_m;
    sum_matrix->_n = matrix_A->_n;
    sum_matrix->_data = matrix_data;

    return sum_matrix;
}

Matrix* matrix_subtraction(Matrix* matrix_A, Matrix* matrix_B) {
    if((matrix_A->_m != matrix_B->_m) || (matrix_A->_n != matrix_B->_n)) {
        return NULL;
    }

    double** matrix_data = malloc(matrix_A->_n * sizeof(double*));

    for(int row = 0; row < matrix_A->_n; row++) {
        matrix_data[row] = malloc(matrix_A->_m * sizeof(int));
        for(int column = 0; column < matrix_A->_m; column++) {
            matrix_data[row][column] = matrix_A->_data[row][column] - matrix_B->_data[row][column];
        }
    }

    Matrix* sum_matrix = malloc(sizeof(*sum_matrix));
    sum_matrix->_m = matrix_A->_m;
    sum_matrix->_n = matrix_A->_n;
    sum_matrix->_data = matrix_data;

    return sum_matrix;
}

Matrix* matrix_multiplication(Matrix* matrix_A, Matrix* matrix_B) {
    if(matrix_A->_m != matrix_B->_n) {
        return NULL;
    }

    Matrix* product_matrix = matrix_create_empty(matrix_A->_n, matrix_B->_m);

    for(int mB_columns_completed = 0; mB_columns_completed < matrix_B->_m; mB_columns_completed++) {
        for(int mA_current_row = 0; mA_current_row < matrix_A->_n; mA_current_row++) {
            double total_sum = 0;
            for(int mA_current_column = 0; mA_current_column < matrix_A->_m; mA_current_column++) {
                total_sum += matrix_A->_data[mA_current_row][mA_current_column] * matrix_B->_data[mA_current_column][mB_columns_completed];
            }
            product_matrix->_data[mA_current_row][mB_columns_completed] = total_sum;
        }
    }

    return product_matrix;
}

void matrix_row_echelon_form(Matrix* matrix) {    
    double complex scalar;

    for(int column = 0; column < matrix->_m; column++) {
        for(int row = 0; row < matrix->_n; row++) {
            if(matrix->_data[row][0] == 0) {
                continue;
            }
            
            // Found a non1 value switch this row to the first row             
            double* tempRow = matrix->_data[0];
            matrix->_data[0] = matrix->_data[row];
            matrix->_data[row] = tempRow;

            for(int row2 = 1; row < matrix->_n; row++) {
                
            }



        }
    }
}

Matrix* matrix_transpose(Matrix* matrix) {
    Matrix* transpose_matrix = matrix_create_empty(matrix->_m, matrix->_n);
    for(int og_row = 0; og_row < matrix->_n; og_row++) {
        for(int og_column = 0; og_column < matrix->_m; og_column++) {
            transpose_matrix->_data[og_column][og_row] = matrix->_data[og_row][og_column];
        }
    }

    return transpose_matrix;
}