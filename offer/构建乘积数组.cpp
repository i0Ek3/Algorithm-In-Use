class Solution {
public:
    vector<int> multiplyArray(const vector<int>& A) {
        vector<int> v;
        int n = A.size();
        if (n == 0) return v;
        v.push_back(1);
        for (int i = 0; i <= n-1; ++i) {
            v.push_back(v.back()*A[i]);
        }
        int tmp = 1;
        for (int i = n-1; i >= 0; --i) {
            v[i] *= tmp;
            tmp *= A[i];
        }
        return v;
    }
};
