#include "matrix.h"
#include <math.h>
#include <complex.h>
#include <stdio.h>

#define UNITYROOT (-1.0 / 2.0) + (sqrt(3) / 2.0) * I

/*
double complex* cubic_formula(double a, double b, double c, double d) {
    double complex* solutions = malloc(3 * sizeof(*solutions));

    double delta_zero = ((b * b) - (3 * a * c));
    double delta_one = ((2 * b * b* b) - (9 * a * b * c) + (27 * a * a * d));

    printf("D1: %f, D0: %f\n", delta_one, delta_zero);

    if(delta_one == 0 && delta_zero == 0) {
        solutions[0] = (b / (-3 * a)) + 0 * I;
        solutions[1] = (b / (-3 * a)) + 0 * I;
        solutions[2] = (b / (-3 * a)) + 0 * I;
        return solutions;
    }

    double complex Cube;

    if(delta_one < 0) {
        Cube = cpow(((delta_one - sqrt((delta_one * delta_one) - (4 * delta_zero * delta_zero * delta_zero))) / 2), 1.0/3.0);
    } else {
        Cube = cpow(((delta_one + sqrt((delta_one * delta_one) - (4 * delta_zero * delta_zero * delta_zero))) / 2), 1.0/3.0);
    }

    double complex w = UNITYROOT;

    solutions[0] = (-1 / (3*a)) * (b + Cube + (delta_zero / Cube));
    solutions[1] = (-1 / (3*a)) * (b + (w * Cube) + (delta_zero / (w * Cube)));
    solutions[2] = (-1 / (3*a)) * (b + (w * w * Cube) + (delta_zero / (w * w * Cube)));

    return solutions;
}
*/

/**
 * @brief A function which finds the eigenvalues of a 2x2 matrix by using the 
 * quadratic formula
 * @param matrix A matrix pointer that contains a 2x2 matrix
 * @returns NULL if the matrix is not a 2x2 Matrix
 * @returns A double complex pointer to a double complex array 
 * that contains two elements with the solutions
*/
double complex *matrix_2x2_find_eigenvalues(Matrix *matrix) {
    if((matrix->_m != 2) && (matrix->_n != 2))
        return NULL;
    
    double complex* eigen_values = malloc(2 * sizeof(*eigen_values));

    double complex discriminant = cpow((cpow((matrix->_data[0][0] + matrix->_data[1][1]), 2) - 
                                      (4.0 * ((matrix->_data[0][0] * matrix->_data[1][1])) - 
                                      (matrix->_data[0][1] * matrix->_data[1][0]))), 1.0/2.0);

    eigen_values[0] = ((matrix->_data[0][0] + matrix->_data[1][1]) + discriminant) / 2.0;
    eigen_values[1] = ((matrix->_data[0][0] + matrix->_data[1][1]) - discriminant) / 2.0;

    return eigen_values;
}

/**
 * @brief A function that find the value of a 3x3 matrix by use of the cubic 
 * formula
 * @param matrix A matrix pointer that contains a 3x3 matrix
 * @returns NULL if the matrix is not 3x3
 * @returns A double complex pointer to a double complex array with 3 elements
 * each containing a different eigenvalue
*/
double complex *matrix_3x3_find_eigenvalues(Matrix *matrix) {
    if((matrix->_m != 3) && (matrix->_n != 3))
        return NULL;

    double b = matrix->_data[0][0] + matrix->_data[1][1] + matrix->_data[2][2];

    double c =  (-matrix->_data[0][0] * matrix->_data[1][1]) -     
                (matrix->_data[0][0] * matrix->_data[2][2]) - 
                (matrix->_data[1][1] * matrix->_data[2][2]) + 
                (matrix->_data[1][2] * matrix->_data[2][1]) + 
                (matrix->_data[0][1] * matrix->_data[1][0]) + 
                (matrix->_data[0][2] * matrix->_data[2][0]); 
    
    double d =  (matrix->_data[0][0] * matrix->_data[1][1] * matrix->_data[2][2]) - 
                (matrix->_data[0][0] * matrix->_data[1][2] * matrix->_data[2][1]) - 
                (matrix->_data[0][1] * matrix->_data[1][0] * matrix->_data[2][2]) + 
                (matrix->_data[0][1] * matrix->_data[1][2] * matrix->_data[2][0]) + 
                (matrix->_data[0][2] * matrix->_data[1][0] * matrix->_data[2][1]) - 
                (matrix->_data[0][2] * matrix->_data[1][1] * matrix->_data[2][0]);

    double complex *solutions = malloc(3 * sizeof(*solutions));

    double delta_zero = ((b * b) + (3 * c));
    double delta_one = ((2 * b * b * b) + (9 * b * c) + (27 * d));

    if (delta_one == 0 && delta_zero == 0) {
        solutions[0] = (b / 3) + 0 * I;
        solutions[1] = (b / 3) + 0 * I;
        solutions[2] = (b / 3) + 0 * I;
        return solutions;
    }

    double complex Cube;

    if (delta_one < 0) {
        Cube = cpow(((delta_one - cpow(((delta_one * delta_one) - 
                   (4 * delta_zero * delta_zero * delta_zero)), 1.0 / 2.0)) / 2.0), 1.0 / 3.0);
    } else {
        Cube = cpow(((delta_one + cpow(((delta_one * delta_one) - 
                   (4 * delta_zero * delta_zero * delta_zero)), 1.0 / 2.0)) / 2.0), 1.0 / 3.0);
    }

    double complex w = UNITYROOT;

    solutions[0] = (b + Cube + (delta_zero / Cube)) / 3.0;
    solutions[1] = (b + (w * Cube) + (delta_zero / (w * Cube))) / 3.0;
    solutions[2] = (b + (w * w * Cube) + (delta_zero / (w * w * Cube))) / 3.0;

    return solutions;
}