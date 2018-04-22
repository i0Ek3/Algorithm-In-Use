// 
// goodFriend.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-22 08:58:22
//
// @Good friend
//  
//  Given the relationship among the digital babies, 
//  how many group can be divided in it, make any 
//  two digital baby in one group are friend, and 
//  any two digital baby in two group are not friend ?
//
// @Case
//  
//  First line you need input two integers n and m(1~n).
//  Then input two integer a and b of the next m lines.
//  Output the number that how many group can be divided.
//
//  input:
//      4 2
//      1 4
//      2 3
//  output:
//      2
//
//
 
#include <cstdio>
const int maxn = 110;
int father[maxn];
bool isRoot[maxn];

int findFather(int x)
{
    if (x == father[x])
    {
        return x;
    }
    else
    {
        int n = findFather(father[x]);
        father[x] = n;
        return n;
    }
}

void unionSet(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb)
    {
        father[fa] = fb;
    }
}

void initial(int n)
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main()
{
    int n, m, a, b;
    int ans = 0;
    scanf("%d%d", &n, &m);
    initial(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        unionSet(a, b);
    }
    
    for (int i = 1; i <= n; i++)
    {
        isRoot[findFather(i)] = true;
    }
    

    for (int i = 0; i <= n; i++)
    {
        ans += isRoot[i];
    }

    printf("%d\n", ans);
    return 0;
}

