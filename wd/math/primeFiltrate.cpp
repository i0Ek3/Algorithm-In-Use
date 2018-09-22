#include <cstdio>
#define N 10000

int prime[N]; // save prime 
int size; // number of prime 
bool mark[N+1]; 

void filtrate() { // prime filtrate 
        for (int i = 1; i <= N; i++) {
                mark[i] = false;
        }
        size = 0;
        for (int i = 2; i <= N; i++) {
                if (mark[i] == true) {
                        continue;
                }
                prime[size++] = i;
                for (int j = i * i; j <= N; j += i) {
                        mark[j] = true;
                }
        }
}


int main()
{
        filtrate();
        int n;
        while (scanf("%d", &n) != EOF) {
                bool isOutput = false;
                for (int i = 0; i < size; i++) {
                        if (prime[i] < n && prime[i] % 10 == 1) {
                                if (isOutput == false) {
                                        isOutput = true;
                                        printf("%d", prime[i]);
                                } else {
                                        printf(" %d", prime[i]);
                                }
                        }
                }
                if (isOutput == false) {
                        printf("-1\n");
                } else {
                        printf("\n");
                }
        }

        return 0;
}

