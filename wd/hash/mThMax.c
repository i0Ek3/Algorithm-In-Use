#include <stdio.h>

#define OFFSET 500000
int hash[1000001];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        
        // 区间范围内，初始化hash数组
        for (int i = -OFFSET; i <= OFFSET; i++) {
            hash[i + OFFSET] = 0;
        }
        
        // 在hash中出现过的都置为1
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            hash[x + OFFSET] = 1;
        }
        
        // 按格式输出
        for (int i = OFFSET; i >= -OFFSET; i--) {
            if (hash[i + OFFSET] == 1) {
                printf("%d", i);
                m--;
                if (m != 0) {
                    printf(" ");
                } else {
                    printf("\n");
                    break;
                }
            }
        }
    }
    
    return 0;
}

