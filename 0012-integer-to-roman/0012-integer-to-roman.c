#include <stdlib.h>
#include <string.h>

/**
 * Given an integer, convert it to a roman numeral.
 * The input is guaranteed to be within the range [1, 3999].
 */
char* intToRoman(int num) {
    // Arrays representing the standard Roman numeral values and their symbols, 
    // ordered from largest to smallest.
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num_symbols = 13;

    // The maximum possible length for the Roman numeral string is for 3888 (MMMDCCCLXXXVIII), 
    // which is 15 characters, plus space for null terminator. 
    // We allocate a safe size.
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0'; // Initialize an empty string
    
    // Iterate through the values array
    for (int i = 0; i < num_symbols; i++) {
        int value = values[i];
        char* symbol = symbols[i];
        
        // While the current number is greater than or equal to the current value, 
        // append the symbol and subtract the value from num.
        while (num >= value) {
            strcat(result, symbol);
            num -= value;
        }
    }
    
    return result;
}
