#include <cstdio>

int fact(int x) {
        if (x == 0) {
                return 1;
        } else {
                return x * fact(x - 1);
        }
}

int main()
{
        int x;
        while (scanf("%d", &x) != EOF) {
                printf("%d\n", fact(x));
        }

        return 0;
}

