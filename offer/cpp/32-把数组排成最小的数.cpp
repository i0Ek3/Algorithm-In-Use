class Solution {
public:
    string PrintfMinNumber(vector<int> nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int&b){
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        string res;
        for (auto i : nums) {
            res += to_string(i);
        }
        return res;
    }
};
