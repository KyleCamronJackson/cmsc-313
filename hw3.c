//cmsc 313 - Matrix Operations Assignment
// Student: Kyle Jackson

#include <stdio.h>
/*
 * Performs matrix multiplication on two 3x3 matrices.
@Param result - 3x3 array to store the multiplication result
@Param   first  - first 3x3 input matrix
@Param    second - second 3x3 input matrix
*/
void matmult(int result[3][3], int first[3][3], int second[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

/*
 * Performs matrix addition on two 3x3 matrices.
@Param result - 3x3 array to store the multiplication result
@Param   first  - first 3x3 input matrix
@Param    second - second 3x3 input matrix
*/
void matadd(int result[3][3], int first[3][3], int second[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

/*
 * Prints a 3x3 matrix with a given label/name in a formatted way.
 @Param   name - character label for the matrix (e.g., 'A', 'B')
 @Param   M    - 3x3 matrix to be printed
*/
void printMatrix(char name, int M[3][3]) {
    printf("    [%d %d %d]\n", M[0][0], M[0][1], M[0][2]);
    printf("%c = |%d %d %d|\n", name, M[1][0], M[1][1], M[1][2]);
    printf("    [%d %d %d]\n\n", M[2][0], M[2][1], M[2][2]);
}

/*
 * Main program execution:
 * 1. Initializes matrices A and B with given values
 * 2. Computes A * B (matrix multiplication)
 * 3. Computes A*B + A (matrix addition)
 * 4. Prints matrices A, B, and the final result
*/
int main() {

    int A[3][3] = {{1, 2, 3}, 
                   {4, 5, 6}, 
                   {7, 8, 9}};

    int B[3][3] = {{1, 2, 0}, 
                   {3, 4, 5}, 
                   {0, 6, 7}};

    int AB[3][3];
    
    int result[3][3];

    // Compute A * B
    matmult(AB, A, B);

    // Compute A*B + A
    matadd(result, AB, A);

    // Print matrices
    printMatrix('A', A);
    printMatrix('B', B);

    // Print result formatted exactly
    printf("        [%d %d %d]\n", result[0][0], result[0][1], result[0][2]);
    printf("A*B+A = |%d %d %d|\n", result[1][0], result[1][1], result[1][2]);
    printf("        [%d %d %d]\n", result[2][0], result[2][1], result[2][2]);

    return 0;
}
