class Solution1 {
public:
    vector<string> Permutation(string str) {
        if (str != " ") dfs(str, 0);
        return res;
    }

private:
    vector<string> res;
    void dfs(string str, int k) {
        int n = str.size();
        if (n == k) {
            res.push_back(str);
            return;
        }
        for (int i = k; i < n; ++i) {
            // 有重复字符时直接跳过
            if (i != k && str[i] == str[k]) continue;
            // 交换两个值，继续dfs
            swap(str[k], str[i]);
            dfs(str, k+1);
        }
    }
};

class Solution2 {
    // use stl
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) return res;
        sort(str.begin(), str.end());
        while (next_permutation(str.begin(), str.eng())) {
            res.push_back(str);
        }
        return res;
    }
};
