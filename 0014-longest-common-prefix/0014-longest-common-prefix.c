char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Start with the first string as the prefix
    char *prefix = strs[0];

    // Compare prefix with each following string
    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        // Move while characters match
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }

        // Shorten prefix to the matched length
        prefix[j] = '\0';

        // If prefix becomes empty, no common prefix
        if (j == 0) {
            return "";
        }
    }

    return prefix;
}