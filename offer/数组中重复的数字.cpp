class Solution {
public:
    bool duplicate(vector<int> num, int n, int *dup) {
        unordered_map<int, bool> m;
        for (int i = 0; i < n; ++i) {
            if (m[num[i]] == true) {
                dup[0] = num[i];
                return true;
            }
            m[num[i]] = true;
        }
        return false;
    }
};
