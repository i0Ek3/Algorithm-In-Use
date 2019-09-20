#include <iostream>

class Solution {
public:
    int rectCover(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        
        int tmp1 = 2;
        int tmp2 = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = tmp1 + tmp2;
            tmp2 = tmp1;
            tmp1 = tmp;
        }
        return tmp1;
    }
};

