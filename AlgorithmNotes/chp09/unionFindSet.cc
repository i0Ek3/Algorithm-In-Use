// 
// unionFindSet.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-21 18:26:52
//
// @Union-Find-Set
// 
//
//
//
//
//

#include <cstdio>
const int maxn = 100010;
int father[maxn];

void initial(int n)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
    }
}

//bad complexity
int findFather1(int x)
{
    if (x == father[x]) return x;
    else return findFather1(x);
}

//good complexity O(1)
int findFather2(int x)
{
    if (x == father[x]) return x;
    else
    {
        int n = findFather2(father[x]);
        father[x] = n;
        return n;
    }
}


void unionSet(int a, int b)
{
    int fa = findFather2(a);
    int fb = findFather2(b);
    while (fa != fb)
    {
        father[fa] = fb;
    }
}


int main()
{


    return 0;
}




