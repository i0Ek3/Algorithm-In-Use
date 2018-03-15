// 
// pat_b1013.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-15 09:12:36
// 
// pat_b1013
// unfinished.
//
 
#include <cstdio>

const int maxn = 1000001;
int prime[maxn],num = 0;
bool p[maxn] = {0};

void find_prime(int n)
{
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false)
        {
            prime[num++] = i;
            if (num >= n) 
                break;
            for (int j = i + i; j < maxn; j += i)
            {
                p[j] = true;
            }
        }
    }
}

int main()
{
    int m,n,count = 0;
    scanf("%d%d",&m,&n);
    find_prime(n);
    for (int i = m; i <= n; i++)
    {
        printf("%d",prime[i-1]);
        count++;
        if (count % 10 != 0 && i < n)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
