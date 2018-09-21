#include <cstdio>
#include <cmath>

int main()
{
        int x;
        while (scanf("%d", &x) != EOF) {
                for (int i = 2; i < (int)sqrt(x) + 1; i++) {
                        if (x % i == 0) {
                                printf("Yes!");
                        } else {
                                printf("No!");
                        }
                }       
        }

        return 0;
}

