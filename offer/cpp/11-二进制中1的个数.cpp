#include <iostream>

class  Solution {
public:
    int number(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};
