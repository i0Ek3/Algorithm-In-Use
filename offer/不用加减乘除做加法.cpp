class Solution {
public:
    int add_(int a, int b) {
        while (b) {
            int tmp = a ^ b; // 二进制每位相加，相当于各位做异或操作
            b = (a & b) << 1; // 计算进位，相当于二进制各位相与，再左移一位
            a = tmp;
        }
        return a;
    }
};
