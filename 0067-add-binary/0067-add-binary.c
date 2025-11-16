#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char* result = (char*)malloc((max_len + 2) * sizeof(char)); // +2 for carry and null terminator
    int carry = 0;
    int i = len_a - 1, j = len_b - 1, k = 0;

    for (; i >= 0 || j >= 0 || carry; k++) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        result[k] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[k] = '\0';
    
    // Reverse the string
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
    return result;
}

int main() {
    char a[] = "11";
    char b[] = "1";
    char* result = addBinary(a, b);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}