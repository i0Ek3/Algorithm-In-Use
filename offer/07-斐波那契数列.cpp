#include <iostream>
using namespace std;

class Solution1 { // O(n) + O(n)
public:
    int fib(int n) {
        int dp[40];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


class Solution2 { // O(n) + O(1)
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;

        int sum = 1; // sum 保存 n-1
        int one = 0; 
        for (int i = 2; i < n; ++i) {
            sum += one;
            one = sum - one;
        }
        return sum;
    }
};

