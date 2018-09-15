// 贪心算法，也作一种算法思想。总是选择当前最好的选择，而不考虑整体情况。
// 另外，有时候贪心算法不容易直接选出最优策略，需要多多推敲一下，并验证策略是否可行。


#include <cstdio>
#include <algorithm>

struct goods {
    double j; // bonds
    double f; // value
    double s; // cost
    bool operator < (const goods & A) const {
        return s > A.s;
    }
}buf[1000];

int main()
{
    double m; // total price
    int n; // goods size
    
    while (scanf("%lf%d", &m, &n) != EOF) {
        if (m < 0 && n < 0) {
            break;
        }
        for (int i = 0; i < n ; i++) {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f; 
        }
        std::sort(buf, buf + n);
        int index = 0;
        double ans = 0;

        while (m > 0 && index < n) {
            if (m > buf[index].f) {
                ans += buf[index].j;
                m -= buf[index].f;
            } else {
                ans += buf[index].j * m / buf[index].f;
                m = 0;
            }
            index++;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}

