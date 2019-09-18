#include <iostream>
#include <vector>
using namespace std;

int rotation(vector<int> num) {
    int n = num.size();
    if (n == 0) return 0;
    for (int i = 0; i< n-1; ++i) {
        if (num[i] > num[i+1]) {
            return num[i+1];
        }
    }
    return num[0];
}


