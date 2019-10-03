class Solution {
public:
    string reverse(string str) {
        string res = "";
        string tmp = "";
        for (unsigned int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                res = " " + tmp + res;
                tmp = "";
            } else {
                tmp += str[i];
            }
        }
        if (tmp.size()) res = tmp + res;
        return res;
    }
};
