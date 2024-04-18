//2D

//q24)
/*
#include <stdio.h>

#define MAX_SIZE 10

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the first matrix:\n");
    readMatrix(mat1, rows, cols);

    printf("Enter elements of the second matrix:\n");
    readMatrix(mat2, rows, cols);

    subtractMatrices(mat1, mat2, result, rows, cols);

    printf("Resultant matrix after subtraction:\n");
    displayMatrix(result, rows, cols);

    return 0;
}

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
*/
//********************************************************************
//q30)
/*
#include <stdio.h>

#define MAX_SIZE 10
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
int areMatricesEqual(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int rows, int cols);
int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the first matrix:\n");
    readMatrix(mat1, rows, cols);
    printf("Enter elements of the second matrix:\n");
    readMatrix(mat2, rows, cols);
    if (areMatricesEqual(mat1, mat2, rows, cols)) {
        printf("Matrices are equal.\n");
    } else {
        printf("Matrices are not equal.\n");
    }

    return 0;
}

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int areMatricesEqual(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return 0;
            }
        }
    }
    return 0;
}
*/