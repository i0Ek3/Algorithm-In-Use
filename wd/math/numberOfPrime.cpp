#include <cstdio>
#define N 100000

bool mark[N + 1];
int prime[N + 1];
int size;

void filtrate() {
        size = 0;
        for (int i = 2; i <= N; i++) {
                if (mark[i] == true) {
                        continue;
                }
                prime[size++] = i;
                if (i >= N / 100) {
                        continue;
                }
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
                int ansPrime[30]; //保存分解后的因子
                int ansSize = 0; //素因数的个数
                int ansNum[30]; //素因数对应的幂指数
                for (int i = 0; i < size; i++) {
                        if (n % prime[i] == 0) {
                                ansPrime[ansSize] = prime[i];
                                ansNum[ansSize] = 0;
                                while (n % prime[i] == 0) {
                                        ansNum[ansSize]++;
                                        n /= prime[i];
                                }
                                ansSize++;
                                if (n == 1) { //若被分解为1，则终止分解
                                        break;
                                }
                        }
                }
                if (n != 1) {
                        ansPrime[ansSize] = n;
                        ansNum[ansSize++] = 1;
                }
                int ans = 0;
                for (int i = 0; i < ansSize; i++) {
                        ans += ansNum[i];
                }
                printf("%d\n", ans);
        }

        return 0;
}

