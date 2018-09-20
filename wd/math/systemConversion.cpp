#include <cstdio>
#include <cstring>
#define N 50

int main()
{
        int a, b;
        char str[N];
        while (scanf("%d%s%d", &a, str, &b) != EOF) {
                int tmp = 0, c = 1, length = strlen(str); // tmp is a system number --> 10 system number, c is weight.
                char ans[N], size = 0;
                
                for (int i = length - 1; i >= 0; i--) {
                        int x;
                        if (str[i] >= '0' && str[i] <= '9') {
                                x = str[i] - '0';
                        } else if (str[i] >= 'a' && str[i] <= 'z') {
                                x = str[i] - 'a' + 10;
                        } else {
                                x = str[i] - 'A' + 10;
                        }
                        tmp += x * c;
                        c *= a;
                }
                
                do {
                        int x = tmp % b;
                        ans[size++] = (x < 10) ? x + '0' : x - 10 + 'A';
                        tmp /= b; 
                } while (tmp);

                for (int i = size - 1; i >= 0; i--) {
                        printf("%c", ans[i]);
                }
                printf("\n");
        }

        return 0;
}

