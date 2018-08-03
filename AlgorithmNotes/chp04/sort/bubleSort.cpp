// 
// bubleSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-05 10:11:02
// 
 
#include <iostream>
#include <stdio.h>

int main()
{
    int a[10] = {3,1,4,5,2};
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 0; j <= 5 - i; j++)
        {
            if(a[i] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}   
