class Solution {
public:
    int GetUglyNumber(int n) {
        if (n < 7) return n; // 0-6都是丑数
        int p2 = 0, p3 = 0, p5 = 0, t = 1; // p为指向队列的指针，t为队列中最小的数
        vector<int> res;
        res.push_back(t)
        while (res.size() < index) {
            t = min(res[p2]*2, min(res[p3]*3, res[p5]*5));
            if (t == res[p2]*2) p2++;
            if (t == res[p3]*3) p3++;
            if (t == res[p5]*5) p5++;
            res.push_back(t);
        }
        return t;
    }
};
