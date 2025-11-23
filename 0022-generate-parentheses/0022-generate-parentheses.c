#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Helper recursive function for backtracking.
 * 
 * @param result Pointer to an array of strings (char**) to store final answers.
 * @param count Pointer to an integer to keep track of the number of solutions found.
 * @param current_string The current string being built.
 * @param open_count Number of opening parentheses used so far.
 * @param close_count Number of closing parentheses used so far.
 * @param max_pairs The target number of pairs (n).
 */
void backtrack(char*** result, int* count, char* current_string, int open_count, int close_count, int max_pairs) {
    // Base case: If we have used all 'n' pairs (length is 2*n), 
    // we have found a valid combination.
    if (strlen(current_string) == 2 * max_pairs) {
        // Allocate memory for the new solution string
        char* solution = (char*)malloc((2 * max_pairs + 1) * sizeof(char));
        if (solution == NULL) return; // Handle allocation failure

        strcpy(solution, current_string);
        
        // Store the solution in the result array
        // We assume the caller (LeetCode environment) has already allocated 
        // sufficient space or we need to reallocate dynamically if necessary.
        // For standard LeetCode C interface, dynamic reallocation is expected.
        *result = (char**)realloc(*result, (*count + 1) * sizeof(char*));
        (*result)[*count] = solution;
        (*count)++;
        return;
    }

    // Recursive Step 1: Add an opening parenthesis if we haven't used all 'n' available opens.
    if (open_count < max_pairs) {
        // Append '(' to the current string
        char temp_string[100]; // Use a sufficiently large temp buffer for recursion
        strcpy(temp_string, current_string);
        strcat(temp_string, "(");
        
        backtrack(result, count, temp_string, open_count + 1, close_count, max_pairs);
    }

    // Recursive Step 2: Add a closing parenthesis if the number of closing 
    // parentheses is less than the number of opening ones (maintains validity).
    if (close_count < open_count) {
        // Append ')' to the current string
        char temp_string[100];
        strcpy(temp_string, current_string);
        strcat(temp_string, ")");

        backtrack(result, count, temp_string, open_count, close_count + 1, max_pairs);
    }
}


/**
 * LeetCode function signature.
 * Note: The return array size is written to the *returnSize pointer.
 */
char ** generateParenthesis(int n, int* returnSize) {
    // Initialize the return size to 0
    *returnSize = 0;
    
    // Dynamically allocate memory for the results array (will be expanded by realloc in backtrack)
    char** result = NULL;
    
    // Start the backtracking process with an empty string, 0 counts, and the target 'n'
    char initial_string[1] = ""; // Start with an empty C string
    backtrack(&result, returnSize, initial_string, 0, 0, n);
    
    return result;
}

// Note: When submitting to LeetCode, you typically only need to paste the 
// `generateParenthesis` function and necessary includes. The test runner 
// handles the main function and memory deallocation internally.

