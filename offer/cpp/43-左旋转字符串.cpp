class Solution {
public:
    string LeftRotateString(string str, int n) {
        string res = "";
        for (unsigned int i = n; i < str.size(); ++i) {
            res.push_back(str[i]);
        }
        for (int i = 0; i < n; ++i) {
            res.push_back(str[i]);
        }
        return res;
    }
};
