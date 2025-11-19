#include <stdio.h>
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

// Helper function for the backtracking algorithm
void backtrack(const char* digits, int index, char* current_combination, char*** result, int* returnSize) {
    if (index == strlen(digits)) {
        // Base case: the current combination is complete
        if (strlen(current_combination) > 0) {
            // Reallocate memory for the results array to add the new string
            *result = (char**)realloc(*result, (*returnSize + 1) * sizeof(char*));
            // Allocate memory for the new string itself and copy the content
            (*result)[*returnSize] = (char*)malloc((strlen(current_combination) + 1) * sizeof(char));
            strcpy((*result)[*returnSize], current_combination);
            (*returnSize)++;
        }
        return;
    }

    // Get the current digit and its corresponding letters
    int digit = digits[index] - '0';
    const char* letters = mapping[digit];

    // Iterate through the letters
    for (int i = 0; i < strlen(letters); i++) {
        // Append the current letter to the combination
        current_combination[index] = letters[i];
        current_combination[index + 1] = '\0'; // Null-terminate the string temporarily

        // Recurse for the next digit
        backtrack(digits, index + 1, current_combination, result, returnSize);

        // Backtrack: the current_combination character at this index will be overwritten 
        // in the next iteration or discarded when returning up the call stack.
    }
}

/**
 * @param digits: A string containing digits from 2-9 inclusive.
 * @param returnSize: A pointer to an integer that will store the size of the returned array.
 * @return: An array of strings containing all possible letter combinations.
 */
char** letterCombinations(char* digits, int* returnSize) {
    // Initialize return size to 0 and result pointer to NULL (for realloc to work like malloc initially)
    *returnSize = 0;
    char** result = NULL;

    // Handle the edge case of an empty input string
    if (digits == NULL || strlen(digits) == 0) {
        return result; // return NULL or empty array as per LeetCode requirements
    }

    // A temporary buffer to build each combination string
    // Max length constraint is 4, plus one for null terminator
    char* current_combination = (char*)malloc(5 * sizeof(char));
    current_combination[0] = '\0';

    // Start the backtracking process
    backtrack(digits, 0, current_combination, &result, returnSize);

    // Free the temporary buffer
    free(current_combination);

    return result;
}

// Example main function for local testing (not needed for LeetCode submission)
/*
int main() {
    char* digits1 = "23";
    int size1;
    char** combos1 = letterCombinations(digits1, &size1);
    printf("Combinations for \"%s\":\n", digits1);
    for (int i = 0; i < size1; i++) {
        printf("%s ", combos1[i]);
        free(combos1[i]); // Remember to free inner strings
    }
    free(combos1); // Remember to free the outer array
    printf("\n");

    char* digits2 = "9";
    int size2;
    char** combos2 = letterCombinations(digits2, &size2);
    printf("Combinations for \"%s\":\n", digits2);
    for (int i = 0; i < size2; i++) {
        printf("%s ", combos2[i]);
        free(combos2[i]);
    }
    free(combos2);
    printf("\n");
    
    char* digits3 = "";
    int size3;
    char** combos3 = letterCombinations(digits3, &size3);
    printf("Combinations for \"%s\": size %d\n", digits3, size3);
    // free(combos3) not needed as it returns NULL

    return 0;
}
*/
