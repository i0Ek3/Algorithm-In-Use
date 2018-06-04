// 
// application1.cc
// @ianpasm(kno30826@gmail.com)
// 2018-06-03 09:28:08
// 
// @Question
//      Given a positive integer sequence A which includes N numbers, with per numbers in sequence, ask the numbers of lower than it with left side in sequence. 
//
// 06-04 add discretization process
//
//
 
#include <cstdio>
#include <cstring>
#include <algorithm>

#define lowbit(i) ((i)&(-i))
const int maxn = 100010;

struct Node
{
    int val;
    int pos;
}temp[maxn];

int c[maxn];
int a[maxn];

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

bool cmp(Node a, Node b)
{
    return a.val < b.val;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp[i].val);
        temp[i].pos = i;
    }
    
    std::sort(temp, temp + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || temp[i].val != temp[i-1].val) {
            a[temp[i].pos] = i + 1;
        } else {
            a[temp[i].pos] = a[temp[i-1].pos]; 
        }
    }
    
    for (int i = 0; i < n; i++) {
        updateSum(a[i], 1);
        printf("%d\n", getSum(a[i]-1));
    }

    return 0;
}
