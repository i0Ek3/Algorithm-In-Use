// 
// hash2.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-08 19:10:31
// 
//Case: 
// Plz enter digits n & m:
// 2 2
// 1   
// 2
// 1
// YES
// 3
// NO
 
#include <cstdio>

const int maxn = 100010;
int hashTable[maxn] = {false};

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
        if (hashTable[x] == true)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}

