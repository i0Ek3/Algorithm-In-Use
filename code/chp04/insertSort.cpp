// 
// insertSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-11-27 09:14:31
// 
 
#include <cstdio>
#define N 512;

int a[N],n;
void insertSort()
{
    for (int i = 2; i <= n; i++)
    {
        int temp = a[i];
        int j = i;
        while (j > 1 && temp < a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

