#include <cstdio>
#define N 50

int main()
{
        int m;
        long long a, b;
        while (scanf("%d", &m) != EOF) {
                int ans[N], size = 0;
                if (m == 0) {
                        break;
                }
                scanf("%lld%lld", &a, &b);
                a += b;
                do {
                        ans[size++] = a % m;
                        a /= m;
                } while (a != 0);
                for (int i = size - 1; i >= 0; i--) {
                        printf("%d", ans[i]);
                }
                printf("\n");
        }
        return 0;
}

