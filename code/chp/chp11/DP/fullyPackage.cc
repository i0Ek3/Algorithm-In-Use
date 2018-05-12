#include <cstdio>
#include <algorithm>

const int maxn = 10;
const int maxv = 1000;

int w[maxn], c[maxv], dp[maxv];

int main()
{
    int n, V;
    scanf("%d%d", &n, &V);
     
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    for (int v = 0; v <= V; v++) {
        dp[v] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= w[i]; v--) {
            dp[v] = std::max(dp[v], dp[v-w[i]] + c[i]);
        }
    }

    int max = 0;
    for (int v = 0; v <= V; v++) {
        if (dp[v] > max) {
            max = dp[v];
        }
    }
    printf("%d", max);

    return 0;
}
