int strStr(char* haystack, char* needle) {
int hayLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    if (needleLen == 0) return 0; // edge case for empty needle
    
    for (int i = 0; i <= hayLen - needleLen; i++) {
        if (strncmp(haystack + i, needle, needleLen) == 0) {
            return i;
        }
    }
    return -1;    
}