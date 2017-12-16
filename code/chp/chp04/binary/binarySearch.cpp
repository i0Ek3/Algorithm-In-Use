 // 
 // binarySearch.cpp
 // ianpasm(kno30826@gmail.com)
 // 2017-12-15 18:05:25
 // 
 
#include <cstdio>

int binarySearch(int A[],int left,int right,int x)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == x)
        {
            return mid;
        }
        else if (A[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    const int n = 10;
    int A[n] = {1,3,4,6,7,8,10,11,12,15};
    printf("The original array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf(".\n");
    printf("The first number we will find 6 and it's index is %d.\n",binarySearch(A,0,n-1,6));
    printf("The second number we will find 9 and it's index is:%d.\n",binarySearch(A,0,n-1,9));
    return 0;
}

