#include <iostream>
using namespace std;

int jump(int n) {
    int res = 1;
    while (--n) {
        res *= 2;
    }
    return res;
}

int jump(int n) {
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n; ++i) {
        dp[i] = 2 * dp[i-1];
    }
    return dp[n];
}

