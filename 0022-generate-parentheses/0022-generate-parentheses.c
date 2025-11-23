#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper recursive function for backtracking.
 * 
 * @param result: A pointer to the dynamically allocated array of result strings.
 * @param returnSize: A pointer to the count of valid strings found so far.
 * @param current_string: The string being built (passed by value for clarity in recursion).
 * @param open_count: Number of opening parentheses used.
 * @param close_count: Number of closing parentheses used.
 * @param n: The target number of pairs.
 */
void backtrack(char*** result, int* returnSize, char* current_string, int open_count, int close_count, int n) {
    // Base case: A valid combination is formed when both counts equal n
    if (open_count == n && close_count == n) {
        // Reallocate memory for the results array to add the new string
        *result = (char**)realloc(*result, (*returnSize + 1) * sizeof(char*));
        
        // Allocate memory for the new string itself and copy the content
        size_t len = strlen(current_string);
        (*result)[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
        strcpy((*result)[*returnSize], current_string);
        
        (*returnSize)++;
        return;
    }

    // Recursive Case 1: Add an opening parenthesis
    // We can add '(' if we haven't reached the limit 'n'
    if (open_count < n) {
        char temp_string[2 * n + 1]; // Use a temporary buffer for the recursive call
        strcpy(temp_string, current_string);
        strcat(temp_string, "(");
        backtrack(result, returnSize, temp_string, open_count + 1, close_count, n);
    }

    // Recursive Case 2: Add a closing parenthesis
    // We can add ')' only if the number of closing < number of opening
    if (close_count < open_count) {
        char temp_string[2 * n + 1]; // Use a temporary buffer for the recursive call
        strcpy(temp_string, current_string);
        strcat(temp_string, ")");
        backtrack(result, returnSize, temp_string, open_count, close_count + 1, n);
    }
}

/**
 * LeetCode Function Signature
 * @param n: The number of pairs of parentheses.
 * @param returnSize: A pointer to an integer that will store the size of the returned array.
 * @return: An array of strings containing all possible letter combinations.
 */
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char** result = NULL; // Initialize result pointer to NULL (for realloc to work like malloc initially)

    if (n <= 0) {
        return result;
    }

    // Start the backtracking process with an empty string and zero counts
    // We pass a local variable "path" to manage the string building
    char path[2 * n + 1];
    path = '\0'; 
    
    backtrack(&result, returnSize, path, 0, 0, n);

    return result;
}

// Example main function for local testing (not needed for LeetCode submission)
/*
int main() {
    int n1 = 3;
    int size1;
    char** combos1 = generateParenthesis(n1, &size1);
    printf("Combinations for n = %d:\n", n1);
    for (int i = 0; i < size1; i++) {
        printf("%s ", combos1[i]);
        free(combos1[i]); // Free inner strings
    }
    free(combos1); // Free the outer array
    printf("\nTotal combinations: %d\n", size1);

    int n2 = 1;
    int size2;
    char** combos2 = generateParenthesis(n2, &size2);
    printf("Combinations for n = %d:\n", n2);
    for (int i = 0; i < size2; i++) {
        printf("%s ", combos2[i]);
        free(combos2[i]); 
    }
    free(combos2); 
    printf("\nTotal combinations: %d\n", size2);

    return 0;
}
*/

  

