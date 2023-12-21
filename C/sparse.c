#include <stdio.h>
#include <Stdlib.h>

int row, col;

typedef struct Element {
    int x, y, val;
    struct Element* next;
} Element;

typedef struct SparseMatrix {
    int row, col, nonZero;
    Element* elements; 
} SparseMatrix;

void inputMatrix(int matrix[row][col], int *num) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter the element at %d,%d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                (*num)++;
        }
    }
    if (*num > (row+col)/2){
        printf("Entered matrix is not a sparse matrix!");
        exit(1);
    }
}

SparseMatrix* createSparseMatrix(int matrix[row][col], int num) {
    SparseMatrix* sparseMatrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sparseMatrix->elements = (Element*)malloc(num*sizeof(Element));

    sparseMatrix->row = row;
    sparseMatrix->col = col;
    sparseMatrix->nonZero = num;

    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix->elements[index].x = i;
                sparseMatrix->elements[index].y= j;
                sparseMatrix->elements[index].val = matrix[i][j];
                index++;
            }
        }
    }
    return sparseMatrix;
}

void printSparseMatrix(SparseMatrix* sparseMatrix) {
    int index = 0;
    for (int i = 0; i < sparseMatrix->row; i++) {
        for (int j = 0; j < sparseMatrix->col; j++) {
            if ((sparseMatrix->elements[index].x==i) 
            && (sparseMatrix->elements[index].y == j)) {
                printf("%d ", sparseMatrix->elements[index].val);
                index++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &row, &col);
    int matrix[row][col];

    int num = 0;
    inputMatrix(matrix, &num);

    SparseMatrix* sparseMatrix = createSparseMatrix(matrix, num);
    printSparseMatrix(sparseMatrix);

    return 0;
}