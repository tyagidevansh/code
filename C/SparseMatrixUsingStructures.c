#include <stdio.h>
#include <stdlib.h>

int ROWS, COLUMNS;

void input_matrix(int matrix[ROWS][COLUMNS]);
void print_matrix(int matrix[ROWS][COLUMNS]);
int count_non_zero(int matrix[ROWS][COLUMNS]);

typedef struct Element {
    int x;
    int y;

    int value;
} * Element;

typedef struct SparseMatrix {
    int ROWS;
    int COLUMNS;
    int NUM_OF_NZERO;

    Element elements;
} * SparseMatrix;

SparseMatrix createSparseMatrix(int matrix[ROWS][COLUMNS], int NUM_OF_NZERO);
void printSparseMatrix(SparseMatrix sparseMatrix);

int main(void) {
    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &ROWS, &COLUMNS);

    int matrix[ROWS][COLUMNS];

    printf("Enter the matrix: \n");
    input_matrix(matrix);

    SparseMatrix sparseMatrix = createSparseMatrix(matrix, count_non_zero(matrix));

    printSparseMatrix(sparseMatrix);

    return 0;
}

void input_matrix(int matrix[ROWS][COLUMNS]) {
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++)
			scanf("%d", &matrix[i][j]);
	}
}

void print_matrix(int matrix[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int count_non_zero(int matrix[ROWS][COLUMNS]) {
    int count = 0;

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLUMNS; j++) {
            if(matrix[i][j])
                count++;
        }
	}

    return 0;
}

SparseMatrix createSparseMatrix(int matrix[ROWS][COLUMNS], int NUM_OF_NZERO) {

    SparseMatrix sparseMatrix = (SparseMatrix) malloc(sizeof(struct SparseMatrix));
    sparseMatrix->elements = (Element) calloc(NUM_OF_NZERO, sizeof(struct Element));

    sparseMatrix->ROWS = ROWS;
    sparseMatrix->COLUMNS = COLUMNS;

    int element;
	for(int i = 0, index = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++) {
            if ((element = matrix[i][j])) {
                sparseMatrix->elements[index].value = element;
                sparseMatrix->elements[index].x = i;
                sparseMatrix->elements[index].y = j;
                ++index;
            }
        }
	}

    return sparseMatrix;
}

void printSparseMatrix(SparseMatrix sparseMatrix) {
    for(int i = 0, index = 0; i < sparseMatrix->ROWS; i++){
		for(int j = 0; j < sparseMatrix->COLUMNS; j++)
            if((sparseMatrix->elements[index].x == i) && (sparseMatrix->elements[index].y == j)) {
                printf("%d\t", sparseMatrix->elements[index].value);
                index++;
            } else {
                printf("0\t");
            }
		printf("\n");
	}
}
