class Solution {
public:
    // 该题想要表达应该是 1 3 x x 5 这个序列，替换两个x后能否成为绝对升序序列
    // 【该条不是本题考虑的范围】但是现在有4张王，所以如果5张牌中，四个王都在的话，是没有问题的
    // 该答案为牛客网友Xy的答案
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        int min = 14, max = -1, flag = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            int num = numbers[i];
            
            if (num == 0) continue;
            if (num < 0 || num > 13) return false;
            
            if ((flag >> num) & 1) return false; // 判断是否有重复的数字
            flag |= (1 << num);
            
            if (num > max) max = num;
            if (num < min) min = num;
            
            if (max-min >= 5) return false;
        }
        return true;
    }
};
