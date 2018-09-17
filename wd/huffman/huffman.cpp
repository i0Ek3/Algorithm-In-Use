#include <cstdio>
#include <queue>

// 小顶堆
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        while (pq.empty() == false) {
            pq.pop();
        }
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            pq.push(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            ans += a + b;
            pq.push(a + b);
        }
        printf("%d\n", ans);
    }
    return 0;
}

