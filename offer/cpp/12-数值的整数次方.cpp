#include <iostream>

class Solution {
public:
    double Power(double base, int exp) {
        if (base == 0.0) return 0.0;
        int e = exp > 0 ? exp : -exp;
        double res = 1.0;
        for (int i = 1; i <= e; ++i) {
            res *= base;
        }
        return exp > 0 ? res : 1/res;
    }
    
};
