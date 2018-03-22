// 
// queue_exp.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-22 09:44:17
// 
 
#include <iostream>
#include <queue>
using std::queue;
using std::cout;
using std::endl;

int main()
{
    queue<int> q;
    for (int i = 1; i < 5; i++)
    {
        q.push(i);
    }
    printf("%d\n",q.size());
    for (int i = 1; i < 3; i++)
    {
        q.pop();
    }
    printf("%d\n",q.size());
    return 0;
}
