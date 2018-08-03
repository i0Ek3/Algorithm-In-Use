// 
// pat_a1052.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-29 10:13:47
//
// @Question
// A linked list consists of a series of structures,which are not necessarily adjacent in
// memory.We assume that each structure contains an integer key and a *Next* pointer to the
// next structure.Now given a linked list, you are supposed to sotr the structures according
// to their key values in increasing order.
//
// @Thinking
// 1. define a static list
// 2. initialize list
// 3. enum list and mark flag then count
// 4. filtrate valid node and sort them of data from small to big
// 5. output outcome
//
//
//
 
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;

struct Node {
    int next, data, address;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b)
{
    if (a.flag == false || b.flag == false)
    {
        return a.flag > b.flag;
    }
    else
    {
        return a.data < b.data;
    }
}

int main()
{
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }

    int address, n, begin;
    scanf("%d%d", &n, &begin); 

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    
    int count = 0, p = begin;
    
    while (p != -1)
    {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }

    if (count == 0)
    {
        printf("0 -1");
    }
    else
    {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address);
        
        for (int i = 0; i < count; i++)
        {
            if (i != count - 1)
            {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);;
            }
            else
            {
                printf("%05d %d - 1\n", node[i].address, node[i].data);
            }
        }
    }
    return 0;
}

