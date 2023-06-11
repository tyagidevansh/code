#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter the value of element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][MAX_SIZE], int rows1, int columns1, int matrix2[][MAX_SIZE], int rows2, int columns2, int result[][MAX_SIZE]) {
    if (columns1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int rows, int columns, int result[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void upperTriangle(int matrix[][MAX_SIZE], int rows, int columns) {
    printf("Upper Triangle of the Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void lowerTriangle(int matrix[][MAX_SIZE], int rows, int columns) {
    printf("Lower Triangle of the Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j <= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, columns1, rows2, columns2, choice;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    inputMatrix(matrix1, rows1, columns1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &columns2);
    inputMatrix(matrix2, rows2, columns2);

    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Upper Triangle\n");
        printf("6. Lower Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows1 == rows2 && columns1 == columns2) {
                    addMatrices(matrix1, matrix2, result, rows1, columns1);
                    displayMatrix(result, rows1, columns1);
                } else {
                    printf("Matrix dimensions do not match!\n");
                }
                break;
            case 2:
                if (rows1 == rows2 && columns1 == columns2) {
                    subtractMatrices(matrix1, matrix2, result, rows1, columns1);
                    displayMatrix(result, rows1, columns1);
                } else {
                    printf("Matrix dimensions do not match!\n");
                }
                break;
            case 3:
                if (columns1 == rows2) {
                    multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2, result);
                    displayMatrix(result, rows1, columns2);
                } else {
                    printf("Matrix dimensions do not match for multiplication!\n");
                }
                break;
            case 4:
                transposeMatrix(matrix1, rows1, columns1, result);
                displayMatrix(result, columns1, rows1);
                break;
            case 5:
                upperTriangle(matrix1, rows1, columns1);
                break;
            case 6:
                lowerTriangle(matrix1, rows1, columns1);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
