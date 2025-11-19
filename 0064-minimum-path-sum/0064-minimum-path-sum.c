#include <stdio.h>
#include <stdlib.h> // Required for malloc and free if not using a fixed-size array

// Helper macro for finding the minimum of two integers
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/**
 * Calculates the minimum path sum from top-left to bottom-right in a grid.
 * 
 * @param grid: The input grid (modified in place). Note: LeetCode uses a pointer-to-pointer approach for 2D arrays in C.
 * @param gridSize: The number of rows (m).
 * @param gridColSize: A pointer to an array containing the number of columns (n) for each row.
 * @return: The minimum path sum.
 */
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    int m = gridSize;
    int n = gridColSize[0]; // Assuming all rows have the same number of columns

    // We can use the input grid itself as the DP table to save space.

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Skip the top-left corner as it's the starting point
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                // For the first row, we can only come from the left
                grid[i][j] += grid[i][j - 1];
            } else if (j == 0) {
                // For the first column, we can only come from above
                grid[i][j] += grid[i - 1][j];
            } else {
                // For all other cells, add the value of the current cell 
                // to the minimum of the cell above it or the cell to the left.
                grid[i][j] += MIN(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }

    // The bottom-right cell now holds the minimum path sum to reach that point.
    return grid[m - 1][n - 1];
}

// Example main function for local testing (requires dynamic memory management setup)
/*
int main() {
    // Example 1: grid = [[1,3,1],[1,5,1],[4,2,1]]
    int m = 3;
    int n = 3;
    int** grid = (int**)malloc(m * sizeof(int*));
    int colSize[3] = {3, 3, 3};

    for(int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
    }

    grid[0][0] = 1; grid[0][1] = 3; grid[0][2] = 1;
    grid[1][0] = 1; grid[1][1] = 5; grid[1][2] = 1;
    grid[2][0] = 4; grid[2][1] = 2; grid[2][2] = 1;

    int minSum = minPathSum(grid, m, colSize);
    printf("The minimum path sum is: %d\n", minSum); // Expected output: 7

    // Free allocated memory
    for(int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
*/


