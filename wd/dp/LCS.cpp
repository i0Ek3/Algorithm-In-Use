#include <cstdio>
#include <cstring>
#define N 100

int dp[N][N];
int max (int a, int b) {
        return a > b ? a : b;
}


int main()
{
        char str1[N], str2[N];
        while (scanf("%s%s", str1, str2) != EOF) {

                int L1 = strlen(str1);
                int L2 = strlen(str2);
        
                for (int i = 0; i <= L1; i++) {
                        dp[i][0] = 0;
                }
                for (int j = 0; j <= L2; j++) {
                        dp[0][j] = 0;
                }

                for (int i = 1; i <= L1; i++) {
                        for (int j = 1; j <= L2; j++) {
                                if (str1[i-1] != str2[j-1]) {
                                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                                } else {
                                        dp[i][j] = dp[i-1][j-1] + 1;
                                }
                        }
                }
                printf("%d\n", dp[L1][L2]);
        }
        
        return 0;
}

