class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        deque<int> dq;
        for (unsigned int i = 0; i < num.size(); ++i) {
            //  从后面依次弹出队列中比当前元素小的数
            while (dq.size() && num[dq.back()] <= num[i]) dq.pop_back();
            // 当当前窗口移出队列首元素的位置，弹出该元素
            while (dq.size() && i-dq.size()+1 > size) dq.pop_front();
            dq.push_back(i); // 将每次滑动的窗口下标加入到队列中
            // 当滑动窗口首地址元素下标i大于等于size时，写入窗口最大值到vector中
            if (size && i+1 > size) res.push_back(num[dq.front()]);
        }
        return res;
    }
}
