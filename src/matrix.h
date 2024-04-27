#ifndef MATRIX
#define MATRIX

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

static int merror = 0;

typedef struct Matrix {
    uint32_t _n;
    uint32_t _m;
    double** _data;
} Matrix;

/**
 * @brief Create a new matrix and fill it with values
 * @param n (uint32_t) The number of rows the matrix has
 * @param m (uint32_t) The number of columns each row has
 * @param va_args (double) The values that are going to be in the matrix
 * The number of inputs in the parameters must equal n x m.
 * @return Malloced Matrix* that is storing the matrix information. Relies on the
 * user to call matrix_delete. 
*/
extern Matrix* matrix_create_fill(uint32_t n, uint32_t m, ...);

/**
 * @brief Create a blank n x m matrix
 * @param n (uint32_t) The number of rows in the matrix
 * @param m (uint32_t) The number of columns in the matrix
 * @return Malloced n x m Matrix* that contains all zeros. It relies on the
 * user to call matrix_delete, and the information can be added by calling
 * matrix_set, matrix_reset_pattern, or matrix_set_start_pattern
*/
extern Matrix* matrix_create_empty(uint32_t n, uint32_t m);

/**
 * @brief Create the identity matrix for a particular R -> (R x R matrix)
 * @param R (uint32_t) The number of dimensions the matrix represents
 * @return Malloced Matrix* of dimension R that contains 1's on the diagonals.
 * Relies on the user to call matrix_delete.
*/
extern Matrix* matrix_create_identity_matrix(uint32_t R);

/**
 * @brief Change just one value of the matrix
 * @param matrix (Matrix*) The pointer to the matrix that is being modified
 * @param n (uint32_t) The row of where the data is being changed (Starts at 0)
 * @param m (uint32_t) The column of where the data is being changed (Starts at 0)
 * @param value (double) The new value located to be placed in [n][m].
*/
extern void matrix_set(Matrix* matrix, uint32_t n, uint32_t m, double value);

/**
 * @brief Change all of the numbers inside of a matrix
 * @param matrix (Matrix*) The pointer to the matrix whose data is being modified
 * @param va_args (double) The arguments that are replacing the data in the matrix.
 * The number of arguments must match the matrix's n x matrix's m. For uneven modifications use
 * matrix_set_start_pattern instead.
*/
extern void matrix_reset_pattern(Matrix* matrix, ...);

/**
 * @brief Change the data of a matrix starting at a particular position
 * @param matrix (Matrix*) The pointer to the matrix being changed
 * @param start_row (uint32_t) The row where the modifications are going to begin
 * (The start of the matrix is at 0)
 * @param strat_column (uint32_t) The column where the modifications are going to begin
 * (The start of the columns is at 0)
 * @param count (uint32_t) The number of modifcations that are being done
 * @param va_args (double) The arguments of the data that is going to be used to change
 * the matrix. The number of arguments for va_args must match the count variable.
*/
extern void matrix_set_start_pattern(Matrix* matrix, uint32_t start_row, uint32_t start_column, uint32_t count, ...);

/**
 * @brief Print the data of the matrix to the stdout.
 * @param matrix (Matrix*) The matrix whose data is being printed to the stdout.
*/
extern void matrix_print(Matrix* matrix);

/**
 * @brief Free the data of a matrix
 * @param matrix (Matrix*) The matrix which is going to be freed.
*/
extern void matrix_delete(Matrix* matrix);

/**
 * @brief Get the data that is located at row, column.
 * @param matrix (Matrix*) The matrix whose data is being received
 * @param row (uint32_t) The row of which the data is being received
 * @param column (uint32_t) The column of which the data is being received
 * @return (double) The data at matrix->_data[row][column]
*/
inline double matrix_get_data(Matrix* matrix, uint32_t row, uint32_t column) {
    return matrix->_data[row][column];
}

/**
 * @brief Get the number of rows the matrix has
 * @param matrix (Matrix*) The pointer to the matrix
 * @return (uint32_t) The number of rows the matrix has
*/
inline uint32_t matrix_get_row_length(Matrix* matrix) {
    return matrix->_n;
}

/**
 * @brief Get the number of columns the matrix has
 * @param matrix (Matrix*) The pointer to the matrix
 * @return (uint32_t) The number of columns the matrix has
*/
inline uint32_t matrix_get_column_length(Matrix* matrix) {
    return matrix->_m;
}

/**
 * @brief Compare the information inside of two matrices
 * @param matrix_A (Matrix*) The first matrix being compared
 * @param matrix_B (Matrix*) The second matrix being compared
 * @return TRUE if every element of matrix_A is equal to matrix_B's elements
 * false if otherwise
*/
extern bool matrix_equals(Matrix* matrix_A, Matrix* matrix_B);

#endif