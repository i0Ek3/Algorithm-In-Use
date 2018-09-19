#include <cstdio>
#include <iostream>
#define N 20

void pd1()
{
        int a, b;
        while (scanf("%d%d", &a, &b) != EOF) {
                int buf1[N], buf2[N]; // to save dismantle place 
                int size1 = 0, size2 = 0;  // size of dismantle place 
                int ans = 0;
                
                // %10 first /10 second can get number of place 
                while (a != 0) {
                        buf1[size1++] = a % 10;
                        a /= 10;
                }
                
                while (b != 0) {
                        buf2[size2++] = b % 10;
                        b /= 10;
                }

                for (int i = 0; i < size1; i++) {
                        for (int j = 0; j < size2; j++) {
                                ans += buf1[i] * buf2[j];
                        }
                }
                
                printf("%d\n", ans);
        }
}

void pd2() {
        char a[N], b[N];
        while (scanf("%s%s", a, b) != EOF) {
                int ans = 0;
                for (int i = 0; a[i] != 0; i++) {
                        for (int j = 0; b[j] != 0; j++) {
                                ans += (a[i] - '0') * (b[j] - '0');
                        }
                }
                printf("%d\n", ans);
        }
}

int main()
{
        //std::cout << "Now is pd1(): " << std::endl;
        //pd1();
        std::cout << "Now is pd2(): " << std::endl;
        pd2();
        return 0;
}

