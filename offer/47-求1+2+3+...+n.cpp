class Solution {
public:

    // 计算1到n的和，不允许使用任何帮助，比如+-*/运算符和库函数等。
    int sum(int n) {// 该思路是短路优先
        int ans = n;
        ans && (ans += sum(n-1));
        return ans;
    }

    int sum(int n) { // 该思路是等差数列求和
        bool a[n][n+1];
        return sizeof(a) >> 1;
    }
};
