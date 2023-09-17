#include <stdio.h>
#include <stdlib.h>

int row, col;

// Defining a new datatype (called Element) of type struct Element*
typedef struct Element {
    int x;
    int y;
    int value;
} *Element;

typedef struct SparseMatrix {
    int row;
    int col;
    int num;
    Element elements;
} *SparseMatrix;

// All the function prototypes
void input_matrix(int matrix[row][col], int *num);
SparseMatrix createSparseMatrix(int matrix[row][col], int num);
void printSparseMatrix(SparseMatrix sparseMatrix);

int main(void) {
    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    int num;
    input_matrix(matrix, &num);

    SparseMatrix sparseMatrix = createSparseMatrix(matrix, num);

    printSparseMatrix(sparseMatrix);

    free(sparseMatrix->elements); // Free dynamically allocated memory
    free(sparseMatrix); // Free sparseMatrix itself

    return 0;
}

void input_matrix(int matrix[row][col], int *num) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter the element at row %d and column %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    if (count > (row * col / 2)) {
        printf("This matrix is not a sparse matrix\n");
        exit(1);
    }
    *num = count;
}

SparseMatrix createSparseMatrix(int matrix[row][col], int num) {
    SparseMatrix sparseMatrix = (SparseMatrix)malloc(sizeof(struct SparseMatrix));
    sparseMatrix->elements = (Element)calloc(num, sizeof(struct Element));

    sparseMatrix->row = row;
    sparseMatrix->col = col;
    sparseMatrix->num = num;

    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix->elements[index].value = matrix[i][j];
                sparseMatrix->elements[index].x = i;
                sparseMatrix->elements[index].y = j;
                index++;
            }
        }
    }
    return sparseMatrix;
}

void printSparseMatrix(SparseMatrix sparseMatrix) {
    int index = 0;
    for (int i = 0; i < sparseMatrix->row; i++) {
        for (int j = 0; j < sparseMatrix->col; j++) {
            if ((sparseMatrix->elements[index].x == i) && (sparseMatrix->elements[index].y == j)) {
                printf("%d ", sparseMatrix->elements[index].value);
                index++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}



