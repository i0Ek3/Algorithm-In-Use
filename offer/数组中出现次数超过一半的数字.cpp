#include <iostream>
#include <vector>
#include <algorithm>
uisng namespace std;

class Solution {
public:
    int MoreThanHalfNum(vector<int> num) { // O(NlogN)
        if (num.empty()) return 0;
        sort(num.begin(), num.end());
        int mid = num[num.size()/2];
        int cnt = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == mid) ++cnt;
        }
        return (cnt > num.size()/2) ? mid : 0;
    }
};
