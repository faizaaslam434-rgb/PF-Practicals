#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Helper function to reverse a string in place
void reverse(char* s, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

/**
 * Given two binary strings a and b, return their sum as a binary string.
 */
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    // The maximum possible length of the result is max(len_a, len_b) + 1 (for potential final carry)
    int max_len = (len_a > len_b ? len_a : len_b);
    
    // Allocate enough memory for the result string (+1 for null terminator)
    // We will build this string in reverse order first
    char* result = (char*)malloc((max_len + 2) * sizeof(char));
    int i = len_a - 1;
    int j = len_b - 1;
    int carry = 0;
    int k = 0; // Index for the result array

    // Iterate while there are digits in either string or a carry remains
    while (i >= 0 || j >= 0 || carry) {
        // Get the numeric value of the current digit, or 0 if we've run past the end of the string
        int digit_a = (i >= 0) ? a[i--] - '0' : 0;
        int digit_b = (j >= 0) ? b[j--] - '0' : 0;
        
        // Calculate the sum of current digits and the carry
        int sum = digit_a + digit_b + carry;
        
        // The current result digit is the remainder when divided by 2 (sum % 2)
        result[k++] = (sum % 2) + '0';
        
        // The new carry is the quotient when divided by 2 (sum / 2)
        carry = sum / 2;
    }
    
    // Null-terminate the string
    result[k] = '\0';
    
    // The result is built in reverse order, so we must reverse it before returning
    reverse(result, k);
    
    return result;
}

/*
// Example Usage (for testing locally):
int main() {
    char* a1 = "11";
    char* b1 = "1";
    char* sum1 = addBinary(a1, b1);
    printf("Input: a=\"%s\", b=\"%s\", Output: \"%s\"\n", a1, b1, sum1);
    free(sum1); 

    char* a2 = "1010";
    char* b2 = "1011";
    char* sum2 = addBinary(a2, b2);
    printf("Input: a=\"%s\", b=\"%s\", Output: \"%s\"\n", a2, b2, sum2);
    free(sum2);
    
    return 0;
}
*/
