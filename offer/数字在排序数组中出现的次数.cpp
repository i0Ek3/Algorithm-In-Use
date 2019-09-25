class Solution {
public:
    int count(vector<int> data, int k) {
        int cnt = 0;
        for (int i = 0; i < data.size(); ++k) {
            if (data[i] == k) cnt++;
        }
        return cnt;
    }

    int count(vector<int> data, int k) {
        auto l = lower_bound(data.begin(), data.end(), k);
        auto r = upper_bound(data.begin(), data.end(), k);
        return r-l;
    }
};
