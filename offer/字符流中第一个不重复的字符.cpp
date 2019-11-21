class Solution {
public:
    string s;
    char h[256] = {0};
    void Insert(char ch) {
        s += ch;
        h[ch]++;
    }

    char FirstAppearingOnce() {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (h[s[i]] == 1) 
                return s[i];
        }
        return '#';
    }
};
