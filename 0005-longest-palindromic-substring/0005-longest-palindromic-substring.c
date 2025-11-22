char* longestPalindrome(char* s) {
    
}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Helper function to expand around a center (left and right pointers)
int expandAroundCenter(char* s, int left, int right) {
    int L = left;
    int R = right;
    // Expand as long as pointers are within bounds and characters match
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }
    // Return the length of the palindrome found (R - L - 1)
    return R - L - 1;
}

// Main function provided by LeetCode interface
char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) < 1) {
        // LeetCode requires returning an empty string or handle null case.
        // For C, you usually return an allocated string or rely on the test environment.
        // Let's assume standard LeetCode behavior where a valid string is returned.
        return ""; 
    }

    int start = 0;
    int maxLength = 0;

    for (int i = 0; i < strlen(s); i++) {
        // Case 1: Odd length palindrome (centered at character s[i])
        int len1 = expandAroundCenter(s, i, i);
        // Case 2: Even length palindrome (centered between s[i] and s[i+1])
        int len2 = expandAroundCenter(s, i, i + 1);

        // Find the maximum length found for centers involving index i
        int currentMaxLen = (len1 > len2) ? len1 : len2;

        // Check if this is the overall longest palindrome found so far
        if (currentMaxLen > maxLength) {
            maxLength = currentMaxLen;
            // Calculate the starting index of the new longest palindrome
            // start = current center index - (palindrome_length - 1) / 2
            start = i - (maxLength - 1) / 2;
        }
    }

    // Allocate memory for the resulting substring
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    if (result == NULL) {
        // Handle malloc failure if necessary (though rare in LeetCode environment)
        return "";
    }
    
    // Copy the characters into the new result buffer
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0'; // Null-terminate the string

    return result;
}

// Note: When submitting to LeetCode, you typically only paste the 
// `longestPalindrome` function and necessary includes. The test runner 
// handles the `main` function and memory deallocation.
