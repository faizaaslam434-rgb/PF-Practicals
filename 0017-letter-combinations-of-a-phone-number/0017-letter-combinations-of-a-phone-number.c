#include <stdlib.h>
#include <string.h>

// Global mapping of digits to letters
const char* mapping[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Backtracking helper function
void backtrack(char* digits, int index, char* current_combination, char** result, int* returnSize, int* capacity) {
    // Base case: If we have processed all digits, add the current combination to the result
    if (index == strlen(digits)) {
        if (*returnSize == *capacity) {
            // Resize the result array if capacity is reached
            *capacity *= 2;
            result = (char**)realloc(result, (*capacity) * sizeof(char*));
        }
        // Allocate memory for a new string and copy the current combination
        result[*returnSize] = (char*)malloc((strlen(digits) + 1) * sizeof(char);
        strcpy(result[*returnSize], current_combination);
        (*returnSize)++;
        return;
    }

    // Get the current digit and its corresponding letters
    int digit = digits[index] - '0';
    const char* letters = mapping[digit];
    int letters_len = strlen(letters);

    // Iterate through all possible letters for the current digit
    for (int i = 0; i < letters_len; i++) {
        current_combination[index] = letters[i];
        // Recursively call backtrack for the next digit
        backtrack(digits, index + 1, current_combination, result, returnSize, capacity);
    }
}

/**
 * Return an array of strings of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits == NULL || strlen(digits) == 0) {
        return NULL;
    }

    // Initialize capacity for the result array
    int capacity = 10;
    char** result = (char**)malloc(capacity * sizeof(char*));
    
    // Allocate space for the temporary combination string
    char* current_combination = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    current_combination[strlen(digits)] = '\0'; // Null-terminate

    // Start the backtracking process
    backtrack(digits, 0, current_combination, result, returnSize, &capacity);

    // Free the temporary combination string
    free(current_combination);

    return result;
}
