// 
// permutation.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-09 09:28:14
// 
 
#include <cstdio>

const int maxn = 11;
int n,p[maxn],hashTable[maxn] = {false};

void generateP(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d",p[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            p[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main()
{
    printf("Plz enter the num n:\n");
    while(scanf("%d",&n) != EOF)
    {
        generateP(1);
    }
    return 0;
}
