// 
// mergeSort.cpp
// ianpasm(kno30826@gmail.com)
// 2018-01-26 09:33:40
//
//Merge Sort
//

#include <cstdio>
#include <cstring>

const int maxn = 100;

void merge(int a[],int l1,int r1,int l2,int r2)
{
    int i = l1,j = l2;
    int temp[maxn],index = 0;
    while (i <= r1 && j <= r2)
    {
        if (a[i] <= a[j])
        {
            temp[index++] = a[i++];
        }
        else
        {
            temp[index++] = a[j++];
        }
    }

    while (i <= r1)
    {
        temp[index++] = a[i++];
    }
    while (j <= r2)
    {
        temp[index++] = a[j++];
    }

    for (int i = 0; i < index; i++)
    {
        a[l1 + i] = temp[i];
    }
}


//recurision
void mergeSort1(int a[],int left,int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort1(a,left,mid);
        mergeSort1(a,mid + 1,right);
        merge(a,left,mid,mid + 1,right);
    }
}


//non-recurision
int min(int l,int r)
{
    int temp = 0;
    if (l > r)
    {
        temp = l;
        l = r;
        r = temp;
    }
    return temp;
}

void mergeSort2(int a[],int n)
{
    for (int step = 2; step / 2 <= n; step *= 2)
    {
        for (int i = 1; i <= n; i += step)
        {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= n)
            {
                merge(a,i,mid,mid + 1,min(i + step - 1,n));
            }
        }
    }
}

//......uncompleted
int main()
{
    int a[] = {66,12,33,57,64,27,18};
    printf("The original array is:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",a[i]);
    }
    mergeSort1(a,66,18);
    mergeSort2(a,7);

    return 0;
}
