class Solution {
public:
    int FindGreatestSumOfArray(vector<int> a) {
        if (a.empty()) return 0;
        int m = INT_MIN;
        int ans = 0;
        for (int i = 0; i < int(a.size()); ++i) {
            ans = max(ans + a[i], a[i]);
            m = max(m, ans);
        }
        return m;
    }
};
