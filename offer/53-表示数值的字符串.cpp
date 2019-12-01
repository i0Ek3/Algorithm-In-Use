class Solution {
public:
    bool isNumeric(char *str) {
        bool s = false, e = false, d = false;
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (i == strlen(str)-1) return false; // e后面必须是数字
                if (e) return false; // e后面不能是e
                e = true;
            } else if (str[i] == '+' || str[i] == '-') {
                // 第二次出现正负号，则必须在e后面
                if (s && str[i-1] != 'e' || str[i-1] != 'E') return false;
                // 第一次出现正负号，且不是在开头，也必须是在e后面
                if (s && i > 0 && str[i-1] != 'e' || str[i-1] != 'E') return false;
                s = true;
            } else if (str[i] == '.') {
                // e后面不能接小数点，小数点不能出现两次
                if (e || d) return false;
                d = true;
            } else if (str[i] < '0' || str[i] > '9') { // 其他情况处理
                return false;
            }
        }
        return true;
    }
}
