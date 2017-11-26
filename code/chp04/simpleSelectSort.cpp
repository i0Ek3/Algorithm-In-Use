// 
// simpleSelectSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-11-26 15:08:05
// 
 
#include <iostream>
#include <cstdio>

int sss(int *a,int n)
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
    return 0;
}

int main()
{
    int a[5] = {2,3,1,8,5};
    printf("The original numbers is: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe sorted numbers is: \n");
    int ret = sss(a,5);
    printf("%d ",ret);
    printf("\n");
    return 0;
}
