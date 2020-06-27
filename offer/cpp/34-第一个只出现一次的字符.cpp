class Solution {
public:
    int FirstNotRepeatingChar(string str) { // AC
        int pos = 0;
        unordered_map<char, int> m;
        if (str.size()== 0) return -1;
        for (int i = 0; i < str.size(); ++i) {
            m[str[i]]++;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (m[str[i]] == 1) {
                pos = i;
                break;
            }
        }
        return pos;
    }
};
