// 
// hash3.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-08 19:21:22
// 
//Case:
// Plz enter digits n & m:
// 2 3
// Plz enter 2 nums x!
// 2 
// 4
// Plz enter 3 nums x!
// 1
// 0
// 2
// 1
// 3
// 0
//
// If x appeared on n then shown 1 else shown 0
//
 
#include <cstdio>

const int maxn = 100010;
int hashTable[maxn] = {0};

int main()
{
    int n,m,x;
    printf("Plz enter digits n & m:\n");
    scanf("%d %d",&n,&m);
    printf("Plz enter %d nums x!\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        hashTable[x]++;
    } 
    printf("Plz enter %d nums x!\n",m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        printf("%d\n",hashTable[x]);
    }

    return 0;
}

