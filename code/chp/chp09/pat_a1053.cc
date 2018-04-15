// 
// pat_a1053.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-15 09:15:25
// 
// 
// @Path of Equal Weight
//
//  Given a tree and its nodes' weight, find the such a path from root to leaf node which path weight sum equals given number S. If you find more please output it with big to small.  
//
// 
// @Case
//
//  input:
//      20 9 24
//      10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
//      00 4 01 02 03 04
//      02 1 05
//      04 2 06 07
//      03 3 11 12 13
//      06 1 09
//      07 2 08 10
//      16 1 15
//      13 3 14 16 17
//      17 2 18 19
//  output:
//      10 5 2 7
//      10 4 10
//      10 3 3 6 2
//      10 3 3 6 2
// 
//
 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct node {
    int weight;
    vector<int> child;
}Node[maxn];

int n, m, S; //n is nodes number, m is path number, S is given sum
int path[maxn]; //record path


bool cmp(int a, int b)
{
    return Node[a].weight > Node[b].weight;
}

//index is current visit node, numNode is nodes numbers on path 
void DFS(int index, int numNode, int sum)
{
    if (sum > S)
    {
        return;
    }

    if (sum == S)
    {
        if (Node[index].child.size() != 0)
        {
            return;
        }

        //output the whole path in path[] when reached leaf nodes
        for (int i = 0; i < numNode; i++)
        {
            printf("% d", Node[path[i]].weight);
            if (i < numNode - 1)
            {
                printf(" ");
            }
            else 
            {
                printf("\n");
            }
        }
        return;
    }

    for (int i = 0; i < Node[index].child.size(); i++)
    {
        int child = Node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Node[i].weight);
    }
    int id, k, child;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);//id for nodes, k is child numbers
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);

    return 0;
}


