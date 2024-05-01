#include <stdio.h>
#include <complex.h>
#include "linalg.h"


int main() {
    
    /*
    Matrix* myMatrix = matrix_create_fill(2, 2, 3.0, 4.0, 2.0, 1.0);
    Matrix* mySecondMatrix = matrix_create_empty(2, 2);

    matrix_reset_pattern(mySecondMatrix, 1.0, 2.0, 4.0, 3.0);

    matrix_print(myMatrix);
    matrix_print(mySecondMatrix);

    matrix_print(matrix_multiplication(myMatrix, mySecondMatrix));
    */

   Matrix* eigenMatrix = matrix_create_fill(2, 2, 2.0, -1.0, -2.0, 1.0);
   matrix_print(eigenMatrix);

    double complex* eigenvalues = matrix_2x2_find_eigenvalues(eigenMatrix);

    printf("Eigenvalues: %f, %f\n", creal(eigenvalues[0]), creal(eigenvalues[1]));


    Matrix* secondMatrix = matrix_create_fill(3, 3, 1.0, 1.0, 9.0, 9.0, 1.0, 3.0, 1.0, 3.0, 3.0);
    matrix_print(secondMatrix);
    printf("\n");
    
    /*
    5, 12, -6
    -3, -12, 6,
    -3, -12, 8
    
    Eigen: 2, 2, -1

    */


    Matrix* thirdMatrix = matrix_create_fill(3, 3, 5.0, 12.0, -6.0, -3.0, -12.0, 6.0, -3.0, -12.0, 8.0);
    matrix_print(thirdMatrix);
    printf("\n");

    double complex* secondValues = matrix_3x3_find_eigenvalues(secondMatrix);
    printf("M2: Eigenvalues: %f, %f, %f\n", creal(secondValues[0]), creal(secondValues[1]), creal(secondValues[2]));

    double complex* thirdValues = matrix_3x3_find_eigenvalues(thirdMatrix);
    printf("M3: Eigenvalues: %f, %f, %f\n", creal(thirdValues[0]), creal(thirdValues[1]), creal(thirdValues[2]));

    return 0;
}