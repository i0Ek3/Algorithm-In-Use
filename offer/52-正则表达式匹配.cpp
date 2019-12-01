class Solution {
public:
    bool match(char *str, char *pattern) {
        // 两个字符串都为空
        if (*str == '\0' && *pattern == '\0') return true;
        // str不为空，p为空
        if (*str != '\0' && *pattern == '\0') return false;
        // 当p的第二个字符不为*
        if (*(pattern+1) != '*') {
            if ((*str == *pattern) || (*str != '\0' && *pattern == ".") {
                return match(str+1, pattern+1);
            } else {
                return false;
            } 
        } else { // 当p的第二个字符为*
            if ((*str == *pattern) || (*str != '\0' && *pattern == ".") {
                return match(str, pattern+2) || match(str+1, pattern);
            } else {
                return match(str, pattern+2);
            }
        }
    }
}
