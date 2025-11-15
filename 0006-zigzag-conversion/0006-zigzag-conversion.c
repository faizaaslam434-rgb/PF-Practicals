#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Converts a string into a zigzag pattern on a given number of rows.
 */
char* convert(char* s, int numRows) {
    if (numRows == 1 || s == NULL || *s == '\0') {
        return s; // No conversion needed or empty/null string
    }

    int len = strlen(s);
    // Allocate memory for the result string (same length as input)
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int res_idx = 0;
    
    // The cycle length of the zigzag pattern
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycleLen) {
            // Add the character at the current index 'j'
            result[res_idx++] = s[j];
            
            // Add the intermediate character for middle rows (i > 0 and i < numRows - 1)
            // The position of the intermediate character is determined by the cycle length minus the current row index offset
            if (i != 0 && i != numRows - 1) {
                int intermediateIdx = j + cycleLen - 2 * i;
                if (intermediateIdx < len) {
                    result[res_idx++] = s[intermediateIdx];
                }
            }
        }
    }
    
    // Null-terminate the result string
    result[len] = '\0';
    return result;
}

/*
// Example Usage (for testing locally):
int main() {
    char* input1 = "PAYPALISHIRING";
    int numRows1 = 3;
    char* output1 = convert(input1, numRows1);
    printf("Input: %s, Rows: %d, Output: %s\n", input1, numRows1, output1);
    free(output1); // Remember to free allocated memory

    char* input2 = "PAYPALISHIRING";
    int numRows2 = 4;
    char* output2 = convert(input2, numRows2);
    printf("Input: %s, Rows: %d, Output: %s\n", input2, numRows2, output2);
    free(output2);
    
    char* input3 = "A";
    int numRows3 = 1;
    char* output3 = convert(input3, numRows3);
    printf("Input: %s, Rows: %d, Output: %s\n", input3, numRows3, output3);
    // No free needed here if numRows == 1 case just returns the original pointer

    return 0;
}
*/
