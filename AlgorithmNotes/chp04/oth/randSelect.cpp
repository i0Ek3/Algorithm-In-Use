// 
// randSelect.cpp
// ianpasm(kno30826@gmail.com)
// 2018-02-01 10:54:55
//
//
//Given a set which consist by different integers,now spreate this set into two part and make its intersection is null, sum is original set.
//at the same time,make the value abs(n1-n2) smallest possible(n is elements numbers),and make the value abs(S1 - S2) biggest possible.
//Ask what's the value of abs(S1 -S2)?
//
//input:
//  13
//  1 6 33 18 4 0 10 5 12 7 2 9 3
//output:
//  80
//
 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int A[maxn],n;

//选取随机主元，对区间[left,right]划分
int randPartition(int A[],int left,int right)
{
    //生成[left,right]区间内的随机数P
    int p = (round(1.0*rand()/RAND_MAX*(right - left) + left));
    swap(A[p],A[left]);
    int temp = A[left];
    while (left < right) //只要left与right不相遇，反复左移right和反复右移left
    {
        while (left < right && A[right] > temp)
            right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp)
            left++;
        A[right] = A[left];
    }
    A[left] = temp; //将temp放在left与right相遇的地方
    return left; //返回相遇的下标
}


//随机选择算法，从区间[left,right]中找到地K大的数，并进行切分
void randSelect(int A[],int left,int right,int K)
{
    if (left == right) //边界
        return ;
    int p = randPartition(A,left,right); //划分后的主元的位置P
    int M = p - left + 1; //A[p]是A[left,right]中的第M大
    if (K == M)
        return ;
    if (K < M) //第K大在主元左侧
    {
        randSelect(A,left,p - 1,K);
    }
    else
    {
        randSelect(A,p + 1,right,K - M);
    }
}

int main()
{
    srand((unsigned)time(NULL)); //初始化随机种子
    int sum = 0,sum1 = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
        sum += A[i];
    }

    randSelect(A,0,n-1,n/2); //寻找第n/2大的数，并进行切分
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += A[i];
    }

    printf("%d\n",(sum - sum1) - sum1);
    return 0;
}
