#include <iostream>
#define N 100
int ans[N][N];

int main()
{
        int n;
        while (scanf("%d", &n) != EOF) {
                for (int k = 1; k <= n; k++) {
                        for (int i = 1; i <= n; i++) {
                                for (int j = 1; j <= n; j++) {
                                        if (ans[i][k] != 0 || ans[k][j] != 0) {
                                                continue;
                                        }
                                        if (ans[i][j] == 0 || ans[i][k] + ans[k][j] < ans[i][j]) {
                                                ans[i][j] = ans[i][k] + ans[k][j];
                                        }
                                }
                        }
                }
        }
        
        return 0;
}

