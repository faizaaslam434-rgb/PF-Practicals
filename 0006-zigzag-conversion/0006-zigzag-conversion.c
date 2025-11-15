char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    char** rows = (char*)malloc(sizeof(char) * numRows);
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(sizeof(char) * (strlen(s) + 1));
        rows[i][0] = '\0';
    }

    int index = 0;
    int step = 1;

    for (int i = 0; i < strlen(s); i++) {
        strcat(rows[index], (char[2]){s[i], '\0'});
        
        if (index == 0) {
            step = 1;
        } else if (index == numRows - 1) {
            step = -1;
        }
        index += step;
    }

    char* result = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    result[0] = '\0';
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);

    return result;
}