#include <stdio.h>

// similar to "int SIZE = 9"
#define SIZE 9

// Function to check which numbers are already in the row
void check_row(int S[SIZE][SIZE], int used[], int r) {//The necessary parameters should be passed
    // to be completed
    for (int i = 0; i < SIZE; i++) {
        used[S[r][i]] = 1;
    }

}

// Function to check which numbers are already in the column
void check_column(int S[SIZE][SIZE], int used[], int c) {//The necessary parameters should be passed
    // to be completed
    for (int i = 0; i < SIZE; i++) {
        used[S[i][c]] = 1;
    } 
}

// Function to check which numbers are already in the 3x3 grid
void check_grid(int S[SIZE][SIZE], int used[], int r, int c) {//The necessary parameters should be passed
    // to be completed
    r /= 3, c /= 3;
    r *= 3, c *= 3;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            used[S[i][j]] = 1;
        }
    }
}


// Function to solve cells that can be immediately solved
int solve_once(int grid[SIZE][SIZE]) {
    int changed = 0;
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (grid[r][c] == 0) {
                int used[SIZE + 1] = { 0 };
                // to be completed
                // check used numbers in row, column and grid by calling the functions

                check_column(grid, used, c);
                check_row(grid, used, r);
                check_grid(grid, used, r, c);

                // Count the number of possible values
                int count = 0, value = 0;
                for (int i = 1; i <= SIZE; i++) {
                    if (used[i] == 0) {
                        count++;
                        value = i;  // Record the only possible value
                    }
                }

                // If exactly one possible value, fill the cell
                if (count == 1) {
                    grid[r][c] = value;
                    changed = 1;
                }
            }
        }
    }
    return changed;
}

// Function to print the Sudoku grid
void print_grid(int S[SIZE][SIZE]) {//The necessary parameters should be passed
    // to be completed
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
}
// Function to solve the Sudoku grid until no more cells can be solved
void solve(int grid[SIZE][SIZE]) {
    while (1) {
        int changed = solve_once(grid);
        if (changed == 0) {
            break;
        }
    }
}



int main() {
    int grid[SIZE][SIZE];

    // Read the Sudoku grid input
    // to be completed
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    solve(grid);
    print_grid(grid);

    return 0;
}