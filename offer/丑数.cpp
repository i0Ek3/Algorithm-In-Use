class Solution {
public:
    int GetUglyNumber(int n) {
        if (n < 7) return n;
        vector<int> res(n);
        res[0] = 1;
        int _2 = 0, _3 = 0, _5 = 0, i;
        for (i = 1; i < n; ++i) {
            res[i] = min(res[_2]*2, res[_3]*3, res[_5]*5));
            if (res[i] == res[_2]*2) _2++;
            if (res[i] == res[_3]*3) _3++;
            if (res[i] == res[_5]*5) _5++;
        }
        return res[n-1];
    }
};
