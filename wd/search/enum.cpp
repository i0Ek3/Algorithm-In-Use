//枚举之百鸡问题

#include <cstdio>

int main()
{
        int n;
        while (scanf("%d", &n) != EOF) {
                for (int x = 0; x <= 100; x++) {
                        for (int y = 0; y <= 100-x; y++) {
                                int z = 100 - x - y;
                                if (3 * 5 * x + 3 * 3 * y + z <= 3 * n) {
                                        printf("x = %d, y = %d, z = %d\n", x, y, z);
                                }
                        }
                } 
        }

        return 0;
}

