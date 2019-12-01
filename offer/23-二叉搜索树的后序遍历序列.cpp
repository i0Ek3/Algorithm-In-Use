class Solution { // 递归
public:
    bool Verify(vector<int> num) {
        if (!num.size()) return 0;
        return helper(num, 0, num.size()-1);
    }
private:
    bool helper(vector<int> num, int l, int r) {
        if (l >= r) return true;
        int i = r;
        while (i > l && num[i-1] > num[r]) --i;
        for (int j = i-1; j >= l; --j) {
            if (num[j] > num[r]) return false;
        }
        return helper(num, l, i-1) && helper(num, i, r-1);
    }
};

class Solution {
public:
    bool verify(vector<int> num) {
        int n = num.size();
        if (!n) return false;
        int i = 0;
        while (--n) {
            while (num[i++] < num[n]); // 后序序列的第一个值和根比较，即左小，比较完毕后i已经到了右子树的第一个值
            while (num[i++] > num[n]); // 开始比较右子树的第一个值和根的值，即右大
            if (i < n) return false;
            i = 0;
        }
        return true;
    }
};
