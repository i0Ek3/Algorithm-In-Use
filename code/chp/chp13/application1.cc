// 
// application1.cc
// @ianpasm(kno30826@gmail.com)
// 2018-06-03 09:28:08
// 
// @Question
//      Given a positive integer sequence A which includes N numbers, with per numbers in sequence, ask the numbers of lower than it with left side in sequence. 
//
//
//
 
#include <cstdio>
#include <cstring>
#define lowbit(i) ((i)&(-i))
const int maxn = 100010;
int c[maxn];

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void updateSum(int x, int v)
{
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int main()
{
    int n, x;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        updateSum(x, 1);
        printf("%d\n", getSum(x-1));
    }
    return 0;
}
