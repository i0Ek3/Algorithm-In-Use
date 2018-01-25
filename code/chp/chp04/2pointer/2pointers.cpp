 // 
 // 2pointers.cpp
 // ianpasm(kno30826@gmail.com)
 // 2018-01-25 11:59:10
 // 
// two pointers

#include <cstdio>

// 1. Given one progressive increase plus integer sequence and one plus integer M,output two numbers which sum is M in different position.
void findNumber()
{
    int n = 9,m;
    int a[] = {1,2,3,4,5,6,7,8,9};
    int i = 0,j = n - 1;

    printf("Please input a num m which less than 17:\n");
    scanf("%d",&m);

    while (i < j)
    {
        if (a[i] + a[j] == m)
        {
            printf("%d %d this two numbers sum is %d! \n",a[i],a[j],m);
            ++i;
            --j;
        }
        else if (a[i] + a[j] < m)
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
}

// 2. Assume there are two progressive increase sequences A,B.Require to merge them into other progressive increase sequence C. 
int mergeSqe(int a[],int b[],int c[],int n,int m)
{
    int i = 0, j = 0,index = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[index++] = a[i++];
        }
        else
        {
            c[index++] = b[j++];
        }
    }
    while (i < n)
    {
        c[index++] = a[i++];
    }
    while (j < n)
    {
        c[index++] = b[j++];
    }

    return index;
}

int main()
{
    // 1
    findNumber();

    // 2
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6,8,10};
    int c[10] = {0};
    mergeSqe(a,b,c,5,5);
    printf("The sequence a is:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe sequence b is:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",b[i]);
    }
    printf("\nAfter merged the sequence c is:\n");
    for (int i = 0 ; i < 10; i++)
    {
        printf("%d ",c[i]);
    }

    return 0;
}


