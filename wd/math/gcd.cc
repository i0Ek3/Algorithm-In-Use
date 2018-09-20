#include <cstdio>

int gcd(int a, int b) {
        if (b == 0) {
                return a;
        } else if (a == 0) {
                return b;
        } else if (a == 0 && b == 0) {
                printf("No gcd yet!");
        } else {
                return gcd(b, a % b);
        } 
}

int main()
{
        int a, b;
        while (scanf("%d%d", &a, &b) != EOF) {
                printf("%d\n", gcd(a, b));
        }

        return 0;
}

