int myAtoi(char* s) {
    int sign = 1;
    long long result = 0;

    // Skip whitespace
    while (*s == ' ') s++;

    // Check sign
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }

    // Convert digits
    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0');
        s++;
    }

    // Apply sign and clamp
    result *= sign;
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}
