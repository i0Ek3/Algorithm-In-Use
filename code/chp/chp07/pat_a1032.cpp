// 
// pat_a1032.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-29 09:28:03
//
// @Question
// Given the first element address and nodes address,data and the next node address in two lists,please find the sharing node's address.If not,return -1.
//
//
//
//
 
#include <cstdio>
#include <cstring>

const int maxn = 100010;

struct Node {
    char data;
    int next;
    bool flag;
}node[maxn];

int main()
{
    int p;

    //traverse full of list
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }

    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    
    for (p = s1; p != -1; p = node[p].next)
    {
        node[p].flag = true;
    }

    for (p = s2; p != -1; p = node[p].next)
    {
        if (node[p].flag == true)
        {
            break;
        }
    }

    if (p != -1)
    {
        printf("%05d\n",p);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}


