class Solution {
public:
    int win(int n, int m) {
        if (n < 1 || m < 1) return -1;
        int j = 0;
        for (int i = 2; i <= n; ++i) {
            j = (j + m) % i;
        }
        return j;
    }
};
