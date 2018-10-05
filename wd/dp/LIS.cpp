#include <cstdio>
#define N 50

int dp[N];
int seq[N]; //save input seq 
int max (int a, int b) {
        return a > b ? a : b;
}


int main()
{
        int n;
        
        while (scanf("%d", &n) != EOF) {
                for (int i = 1; i <= n; i++) {
                        scanf("%d", &seq[i]);
                }
                for (int i = 1; i <= n; i++) {
                        int intial_max = 1;
                        for (int j = 1; j < i; j++) {
                                if (seq[j] >= seq[i]) {
                                        intial_max = max(intial_max, dp[j] + 1);
                                }
                        }
                        dp[i] = intial_max;
                }
                int ans = 1;
                for (int i = 1; i <= n; i++) {
                        ans = max(ans, dp[i]);
                }
                printf("%d\n", ans);
        }
        
        return 0;
}

