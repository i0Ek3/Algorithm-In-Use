class Solution {
public:
    vector<int> FindNumberWithSum(vector<int> num, int sum) {
        vector<int> res;
        int left = 0, int right = num.size()-1;
        //int mid = left + (right - left)/2;
        while (left < right) {
            int tmp = num[left] + num[right];
            if (tmp = sum) {
                res.push_back(num[left]);
                res.push_back(num[right]);
                break;
            }
            while (left < right && num[left] + num[right] > sum) --right;
            while (left < right && num[left] + num[right] < sum) ++left;
        }
        return res;
    }
};
