class Solution { // 依然不太懂
public:
    int countDigitOne(int n) { // O(n)
        int cnt = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int a = n / m;
            int b = n % m;

            // 加8的原因在于不会产生进位，不影响计算1的个数
            cnt += (a+8) / 10*m + (a%10 == 1) * (b+1);
        }
        return cnt;
    }
};

class Solution {  // O(nlogn)
public:
    int numbersOf1(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            int tmp = i;
            while (tmp) {
                if (tmp % 10 == 1) {
                    cnt++;
                }
                tmp /= 10;
            }
        }
        return cnt;
    }
};


// python
//
class Solution:
    def NumberOf1Between1AndN(self, n):
        cnt = 0
        for i in range(1, n+1):
            for i in str(i):
                if i == '1':
                    cnt += 1
        return cnt
