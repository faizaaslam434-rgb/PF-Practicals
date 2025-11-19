#include <stdbool.h>
#include <stdio.h>

/**
 * Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it in place.
 * 
 * @param matrix: The input grid (modified in place). LeetCode uses a pointer-to-pointer approach for 2D arrays in C.
 * @param matrixSize: The number of rows (m).
 * @param matrixColSize: A pointer to an array containing the number of columns (n) for each row.
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL) {
        return;
    }

    int m = matrixSize;
    // We assume all rows have the same number of columns, take the size of the first row
    int n = matrixColSize[0]; 

    // Use a boolean flag to track if the first column needs to be zeroed out later.
    bool first_col_zero = false;

    // Step 1: Scan the matrix to mark the first row and first column
    for (int i = 0; i < m; i++) {
        // Check if any element in the first column is zero
        if (matrix[i][0] == 0) {
            first_col_zero = true;
        }

        // Iterate from the second column (j=1) onwards
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                // Mark the start of the current row (i, 0)
                matrix[i][0] = 0;
                // Mark the start of the current column (0, j)
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Iterate through the matrix again, starting from (1, 1), 
    // and use the marks to set the rest of the cells to zero.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // If the marker in its corresponding row-start or column-start is 0, set current cell to 0.
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Use the markers to set the first row and first column themselves to zero
    
    // Set the first row to zero if its marker (matrix[0][0]) is 0
    if (matrix[0][0] == 0) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Set the first column to zero if our flag was set in Step 1
    if (first_col_zero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
