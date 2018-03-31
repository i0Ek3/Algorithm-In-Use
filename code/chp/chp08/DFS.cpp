// 
// DFS.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-31 08:57:01
// 
// 背包问题
// 
//
//
 
#include <cstdio>

const int maxn = 30;
// n goods, and the capcity of bag is V, the max value is maxValue
int n, V, maxValue = 0;
int w[maxn], c[maxn];

// index is current goods id, sumW and sumC is current goods weight and value
void DFS(int index, int sumW, int sumC)
{
    // border
    if (index == n)
    {
        if (sumW <= V && sumC > maxValue)
        {
            maxValue = sumC;
        }
        return;
    }
    // recursion
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}

void DFS_optimizing(int index, int sumW, int sumC)
{
    if (index == n)
    {
        return;
    }
    DFS_optimizing(index + 1, sumW, sumC);
    if (sumW + w[index] <= V)
    {
        if (sumC + c[index] > maxValue)
        {
            maxValue = sumC + c[index];
        }
        // select number n goods
        DFS_optimizing(index + 1, sumW + w[index], sumC + c[index]);
    }
}

int main()
{
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
    {
        // the value of every goods
        scanf("%d", &c[i]); 
    }

    for (int i = 0; i < n; i++)
    {
        // the weight of every goods
        scanf("%d", &w[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    printf("\n========after optimizing=========\n");
    DFS_optimizing(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;
}


