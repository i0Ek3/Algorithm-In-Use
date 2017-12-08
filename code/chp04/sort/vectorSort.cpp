// 
// vectorSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-05 10:38:59
// 
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using std::vector;
using std::cout;
using std::endl;

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    vector<int> vi;
    for (int i = 0; i < 5; i++)
    {
        vi.push_back(i);
    }
    sort(vi.begin(),vi.end(),cmp);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",vi[i]);
    }
    return 0;
}
