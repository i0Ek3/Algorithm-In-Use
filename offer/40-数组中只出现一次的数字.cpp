class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < data.size(); ++i) m[data[i]]++;
        for (int i = 0; i < data.size(); ++i)  {
            if (map[data[i]] == 1) res.push_back(data[i]);
        }
        *num1 = res[0];
        *num2 = res[1];
    }

    void 2(vector<int> data, int* n1, int* n2) {
        int dif = accumulate(data.begin(), data.end(), 0, bit_xor<int>());
        dif &= -dif;
        *n1 = 0, *n2 = 0;
        for (auto d : data) {
            if (!(d & dif)) *n1 ^= d;
            else *n2 ^= d;
        }
    }
};
