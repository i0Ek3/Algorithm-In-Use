// 
// simpleSelectSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-11-26 15:08:05
// 
 
#include <iostream>
#include <cstdio>

void sss(int *a,int n)
{
    int i,j,k;
    for (int i = 1; i <= n; i++)
    {
        int k =i;
        for (int j = i; j <= n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
    }

    int temp = a[i];
    a[i] = a[k];
    a[k] = temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}

#if 0
int main()
{
    int b[5];
    printf("The original numbers is: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",b[i]);
    }
    printf("\nThe sorted numbers is: \n");
    sss(b[2,3,1,8,5],5);
    printf("\n");
    return 0;
}
#endif

