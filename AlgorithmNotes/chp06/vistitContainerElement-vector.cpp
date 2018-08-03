// 
// vistitContainerElement.cpp
// ianpasm(kno30826@gmail.com)
// 2018-02-26 08:41:01
// 
 
#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::iterator;

int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }

    // 01
    //vector<int>::iterator it = vi.begin();
    //for (int i = 0; i < 5; i++)
    //{
    //    printf("%d ",*(it + i));
    //}
    
    //02
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        printf("%d ",*it);
    }
    return 0;

}
