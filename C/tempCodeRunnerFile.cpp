#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> row2 >> col2;

    int matrix1[row1][col1], matrix2[row2][col2], matrix3[row1][col2];

    if (col1 != row2) {cout << "These matrices cannot be multiplied!";return 1;}

    for (int i = 0; i < row1; i++) {for (int j = 0; j < col1; j++) {
            cout << "Enter the value of " << i + 1 << ", " << j + 1 << " for the first matrix: ";
            cin >> matrix1[i][j];}}

    for (int i = 0; i < row2; i++) {for (int j = 0; j < col2; j++) {
            cout << "Enter the value of " << i + 1 << ", " << j + 1 << " for the second matrix: ";
            cin >> matrix2[i][j];}}

    for (int i = 0; i < row1; i++) {for (int j = 0; j < col2; j++) {matrix3[i][j] = 0;
            for (int k = 0; k < col1; k++) {matrix3[i][j] += matrix1[i][k] * matrix2[k][j];}
            cout << matrix3[i][j] << ' ';}
        cout << '\n';}
        
return 0;
}