#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("-----------\n");
        }
        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0) {
                printf("|");
            }
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the number can be placed at the given position
bool canPlace(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check the row and column
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    return true;
}

int main() {
    int grid[SIZE][SIZE] = {0};
    int moves, row, col, num, level;

    printf("Enter difficulty level (1-5): ");
    scanf("%d", &level);

    // Set the number of moves according to difficulty level
    moves = 500 / level;

    while (moves > 0) {
        printGrid(grid);

        printf("Enter row (1-9), column (1-9) and number (1-9): ");
        scanf("%d %d %d", &row, &col, &num);

        // Adjusting indices to 0-based
        row--;
        col--;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || num < 1 || num > 9) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (canPlace(grid, row, col, num)) {
            grid[row][col] = num;
            moves--;
        } else {
            printf("Cannot place number here. Please try again.\n");
        }
    }

    printf("Final grid:\n");
    printGrid(grid);

    return 0;
}
