#include <stdbool.h>
#include <stdio.h>

/**
 * Determines if a 9x9 Sudoku board is valid.
 * 
 * @param board: The 9x9 Sudoku board represented as a 2D array of characters.
 * @return: true if the board is valid, false otherwise.
 */
bool isValidSudoku(char board[9][9]) { // Correct function signature
    // We use three 9x9 integer arrays (acting as boolean flags)
    // to track occurrences of digits 1-9 (indexed 0-8).
    int seen_rows[9][9] = {0};
    int seen_cols[9][9] = {0};
    int seen_boxes[9][9] = {0};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            // Skip empty cells
            if (board[r][c] == '.') {
                continue;
            }

            // Convert character digit to a 0-based index (0-8)
            int num_index = board[r][c] - '1'; 
            
            // Calculate the index of the 3x3 sub-box (0-8)
            // (r/3) determines the vertical block (0, 1, 2)
            // (c/3) determines the horizontal block (0, 1, 2)
            int box_index = (r / 3) * 3 + (c / 3);

            // Check for existing occurrences in row, column, or box
            if (seen_rows[r][num_index] || seen_cols[c][num_index] || seen_boxes[box_index][num_index]) {
                return false; // Violation found
            }

            // Mark the number as seen in all three tracking arrays
            seen_rows[r][num_index] = 1;
            seen_cols[c][num_index] = 1;
            seen_boxes[box_index][num_index] = 1;
        }
    }

    // If the entire board is traversed without any violations, it is valid
    return true;
}

// Example main function for local testing
/*
int main() {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board)) {
        printf("The Sudoku board is Valid.\n");
    } else {
        printf("The Sudoku board is Invalid.\n");
    }

    return 0;
}
*/
