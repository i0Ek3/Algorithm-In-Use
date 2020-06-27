#define ll long long

class Solution {
public:
    // 归并排序，答案来自牛友rs勿忘初心
    int InversePairs(vector<int> data) {
        int len = data.size();
        if (len <= 0) return 0;
        vector<int> copy;
        for (int i = 0; i < len; ++i) {
            copy.push_back(data[i]);
        }
        ll c = helper(data, copy, 0, len-1);
        return c % 1000000007;
    }
private:
    ll helper(vector<int> &data, vector<int> &copy, int beg, int end) {
        if (beg == end) {
            copy[beg] = data[beg];
            return 0;
        }
        int len = (end - beg) / 2;
        ll left = helper(copy, data, beg, beg+len);
        ll right = helper(copy, data, beg+len+1, end);

        int i = beg + len;
        int j = end;
        int idx = end;
        ll c = 0;
        while (i >= beg && j >= beg+len+1) {
            if (data[i] > data[j]) {
                copy[idx--] = data[i--];
                c += j - beg - len;
            } else {
                copy[idx--] = data[j--];
            }
        }
        for (; i >= beg; --i) {
            copy[idx--] = data[i];
        }
        for (; j >= beg+len+1; --j) {
            copy[idx--] = data[j];
        }
        return left+right+c;
    }
};
