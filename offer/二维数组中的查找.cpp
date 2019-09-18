#include <iostream>
using namespace std;

class Solution {
public:
    bool find(int tar, vector<vector<int>> num) {
        int n = num.size();
        int m = num[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (num[i][j] == tar) return true;
            }
        }
        return false;
    }
};

