#include "../src/matrix.h"
#include "../src/matrix_base_operations.h"


int main() {
    Matrix* matrix = matrix_create_fill(2, 3, 3.0, 4.0, 2.0, 5.0, 6.0, 7.0);

    matrix_print(matrix);
    Matrix* t_matrix = matrix_transpose(matrix);

    matrix_print(t_matrix);
    matrix_print(matrix_transpose(t_matrix));

}