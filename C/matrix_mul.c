#include <stdio.h>

int main(){

    int row1,col1,row2,col2, val;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf(" %d %d", &row1, &col1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf(" %d %d", &row2, &col2);

    int matrix1[row1][col1], matrix2[row2][col2], matrix3[row1][col2];

    if(col1!=row2)
    {
        printf("These matrices cannot be multiplied!");
        return 1;
    }

     for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            printf("Enter the value of %d, %d for the first matrix: ", i + 1, j + 1);
            scanf(" %d", &matrix1[i][j]);
  
        }
     }

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("Enter the value of %d, %d for the second matrix: ", i + 1, j + 1);
            scanf(" %d", &matrix2[i][j]);
        }
    }

    for(int i =0; i< row1;i++){
        for(int j=0; j<col2;j++ ){
            matrix3[i][j]= 0;
            for (int k=0; k< col1;k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}