class Solution {
public:
    bool right(vector<int> in, vector<int> out) {
        if (!in.size()) return false;
        vector<int> s;
        for (int i = 0, j = 0; i < in.size();) {
            s.push_back(in[i++]);
            while (j < out.size() && s.back() == out[j]) {
                s.pop_back();
                j++;
            }
        }
        return s.empty();
    }
};
