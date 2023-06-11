#include <stdio.h>

void print(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < m; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void addsub(int a) {
    int n, m, val;
    printf("Enter the number of rows and columns: ");
    scanf(" %d %d", &n, &m);
    int matrix1[n][m], matrix2[n][m], matrix3[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter the value of %d, %d for the first matrix: ", i + 1, j + 1);
            scanf(" %d", &val);
            matrix1[i][j] = val;

            printf("Enter the value of %d, %d for the second matrix: ", i + 1, j + 1);
            scanf(" %d", &val);
            matrix2[i][j] = val;

            switch(a)
            {
                case 1:
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];

                case 2:
                matrix3[i][j] = matrix1[i][j] - matrix2[i][j];

            }
                
        }
    }

    print(n, m, matrix3);
}

int product()
{
    int l,m,n,o, val;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf(" %d %d", &l, &m);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf(" %d %d", &n, &o);

    int matrix1[l][m], matrix2[n][o], matrix3[l][o];

    if(m!=n)
    {
        printf("These matrices cannot be multiplied!");
        goto end;
    }

     for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter the value of %d, %d for the first matrix: ", i + 1, j + 1);
            scanf(" %d", &val);
            matrix1[i][j] = val;
        }
     }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < o; j++) {
            printf("Enter the value of %d, %d for the second matrix: ", i + 1, j + 1);
            scanf(" %d", &val);
            matrix2[i][j] = val;
        }
    }

    for(int i =0; i< l;i++){
        for(int j=0; j<o;j++ ){
            matrix3[i][j]= 0;
            for (int k=0; k< m;k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    end:
    return 1;
    
}

void transpose() {
    int n, m;
    printf("Enter the number of rows and columns in your matrix: ");
    scanf("%d %d", &n, &m);

    int matrix1[n][m], matrix2[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter the value of element at position %d %d for the matrix: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("The transpose of the matrix is:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix2[i][j] = matrix1[j][i]; 
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

}

void triangles()
{
    int n, m;
    printf("Enter the number of rows and columns in your matrix: ");
    scanf("%d %d", &n, &m);

    int matrix1[n][m], diagonal[n], upper[n*(n - 1)/2], lower[n*(n - 1)/2];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter the value of element at position %d %d for the matrix: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Upper triangle: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(j > i){
                printf("%d ", matrix1[i][j]);
            }
        }
        printf("\n");
    }

    printf("Lower triangle: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(j < i){
                printf("%d ", matrix1[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number corresponding the operation you want to perform: \n"
            "1. Addition of two matrices \n"
            "2. Subtraction of two matrices \n"
            "3. Product of two matrices \n"
            "4. Transpose of a matrix \n"
            "5. Finding upper and lower triangular matrices \n");
    scanf("%d", &n);

    switch(n)
    {
        case 1:
            addsub(1);
            break;
        
        case 2:
            addsub(2);
            break;
        
        case 3:
            product();
            break;
        
        case 4:
            transpose();
            break;
        
        case 5: 
            triangles();
            break;
    }
    return 0;
}