
void state1() {
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                        dp[i][j] = max(dp[i-1][j+1], dp[i-1][j-1]);
                }
        }
        int ans = dp[n][m];
}



int state2() {
        int *src;
        int *des;
        int n, m;
        while (scanf("%d%d", &n, &m) != EOF) {
                for (int i = 1; i <= n; i++) {
                        std::swap(src, des);
                        for (int j = 1; j <= m; j++) {
                                des[j] = std::max(src[j+1], src[j-1]);
                        }
                }
                int ans = des[m];
        }
}


