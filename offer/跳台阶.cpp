#include <iostream>
using namespace std;

int jump(int n) {
    if (n <= 2) return n;

    int n1 = 2;
    int n2 = 1;

    for (int i = 3; i <= n; ++i) {
        int tmp = n1 + n2;
        n2 = n1;
        n1 = tmp;
    }
    return n1;
}

