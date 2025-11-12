int romanToInt(char * s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int value = 0;
        int nextValue = 0;

        // Get current symbol value
        switch (s[i]) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
        }

        // Get next symbol value (if it exists)
        switch (s[i + 1]) {
            case 'I': nextValue = 1; break;
            case 'V': nextValue = 5; break;
            case 'X': nextValue = 10; break;
            case 'L': nextValue = 50; break;
            case 'C': nextValue = 100; break;
            case 'D': nextValue = 500; break;
            case 'M': nextValue = 1000; break;
        }

        // If current value is smaller than next, subtract it
        if (value < nextValue)
            total -= value;
        else
            total += value;
    }

    return total;
}