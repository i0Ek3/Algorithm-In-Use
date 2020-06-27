#include <iostream>
#include <vector>
#include <algorithm>
uisng namespace std;

class Solution {
public:
    int MoreThanHalfNum(vector<int> num) {
        if (num.size() == 0) return 0;
        int n = num[0], cnt = 1;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == n) cnt++;
            else cnt--;
            if (cnt == 0) {
                n = num[i];
                cnt = 1;
            }
        }
        cnt = 0;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == n) cnt++;
        }
        return (cnt > num.size()/2) ? n : 0;
    }


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
