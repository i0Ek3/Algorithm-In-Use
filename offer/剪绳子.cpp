class Solution {
public:
    // 数学
    int cutRope(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        else return pow(3, n/3)*(n%3);
    }
    
    // 动态规划
    int cutRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int dp[n+1];
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        int tmp = 0;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i/2; ++j) {
                tmp = max(tmp, dp[j]*dp[i-j]);
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
