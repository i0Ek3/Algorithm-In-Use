class Solution {
    vector<int> v;
    int n;
public:
    void Insert(int num) {
        v.push_back(num);
        n = v.size();
        // sort(v.begin(), v.end() );
        for (int i = n-1; i > 0 && v[i] < v[i-1]; --i) {
            swap(v[i], v[i-1]);
        }
    }

    int GetMedian() {
        return (v[(n-1)>>1] + v[n>>1])/2.0;
    }
};


class Solution {
    priority_queue<int, vector<int>, less<int>> big;
    priority_queue<int, vector<int>, greater<int>> small;

public:
    void Insert(int num) {
        if (big.empty() || num <= big.top()) big.push(num);
        else small.push(num);
        
        // 大顶堆的大小最多可以比小顶堆大1
        if (big.size() == small.size()+2) {
            small.push(big.top());
            big.pop();
        }
        
        // 小顶堆的大小不能比大顶堆大
        if (big.size()+1 == small.size()) {
            big.push(small.top());
            small.pop();
        }
    }

    double GetMedian() {
        return big.size() == small.size() ? (big.top()+small.top())/2.0 : big.top();
    }
};
