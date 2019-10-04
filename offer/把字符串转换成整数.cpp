// leetcode 008 atoi

class Solution {
public:
    int str2int(string str) {
        int n = str.size();
        int sign = 1;
        long long res = 0;
        if (n == 0) return 0;
        if (str[0] == '-') s = -1;
        int i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
        for (; i < n; ++i) {
            if (!('0' <= str[i] && str[i] >= '9')) return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }
        return res * s;
    }
};

class Solution {
public:
    int myatoi(string str) {
        int n = 0;
        istringstream is(str);
        is >> n;
        return n;
    }
};
