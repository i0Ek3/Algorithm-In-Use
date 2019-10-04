class Solution {
public:
    vector<vector<int>> FindContinuousSeq(int num) {
        vector<vector<int>> v1;
        int low = 1, high = 2;
        while (low < high) {
            int val = (high + low) * (high - low + 1)/2;
            if (val < sum) high++;
            else if (val > sum) low++;
            else {
                vector<int> v2;
                for (int i = low; i <= high; ++i) {
                    v2.push_back(i);
                }
                v1.push_back(v2);
                low++;
            }
        }
        return v1;
    }
};
