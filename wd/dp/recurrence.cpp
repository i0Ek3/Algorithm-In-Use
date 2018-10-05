//递推

#include <cstdio>
#define N 50

long long recurrence[N];

int main()
{
        int n;
        recurrence[1] = 1;
        recurrence[2] = 2;
        for (int i = 3; i <= N; i++) {
                recurrence[i] = recurrence[i-1] + recurrence[i-2];
        }
        while (scanf("%d", &n) != EOF) {
                printf("%lld\n", recurrence[n]);
        }

        return 0;
}

