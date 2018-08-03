// 
// hash1.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-08 18:42:10
// 
// Given n,m nums,ask is there some nums in m appears on n?
// 
//Case:
// Plz enter digit n and m divided with blank : 
// 2 3
// Plz enter 2 nums x!
// 1
// 2
// Plz enter 3 nums x!
// 1
// YES
// 2
// YES
// 3
// NO
 
#include <cstdio>

const int maxn = 100010;
bool hashTable[maxn] = {false};

int main()
{
    int n,m,x;
    printf("Plz enter digit n and m divided with blank : \n");
    scanf("%d %d",&n,&m);
    printf("Plz enter %d nums x!\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        hashTable[x] = true;
    }
    printf("Plz enter %d nums x!\n",m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        if (hashTable[x] == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

