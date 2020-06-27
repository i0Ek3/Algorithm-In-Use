#include <iostream>
#include <vector>

class Solution {
public:
    void reorder(vector<int>& num) {
        vector<int> res;
        for (auto i : num.size()) {
            if (num[i] & 1) res.push_back(num[i]);
        }
        for (auto i : num.size()) {
            if (!(num[i]&1)) res.push_back(num[i]);
        }
        num = res;
    }
};

