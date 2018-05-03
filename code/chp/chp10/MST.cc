// 
// MST.cc
// @ianpasm(kno30826@gmail.com)
// 2018-05-03 08:52:35
//
// @MST--Minimum Spanning Tree
//  
//  @Defination
//      Given an undirection graph G(V, E), find the tree T then make this tree holds all nodes and some edges form G with minimum weight.
//
//  @Nature
//      1. MST is a tree, line = node - 1, without ring in tree 
//      2. With G, MST can not the only one, but sum of lines weights is only 
//      3. The root of MST could be any node 
//
//  @Solution:
//      1. Prim
//          Thought same with dijkstra but d[] has different means.
//
//      2. Kruskal
//          Thought of this algorithm is sort all edges weight from big to small, judeg this two nodes not in the same block, if not discard this edge, loop this process until line = node - 1. 
//
//
//
// 
#include <cstdio> 
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

struct Node //Adjacent link 
{
    int v, dis;
};

struct edge //kruskal
{
    int u, v;
    int cost;
}E[MAXV];

vector<Node> Adj[MAXV];
bool visit[MAXV] = {false};
int n, d[MAXV], G[MAXV][MAXV];

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

int Prim1()
{
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {   
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        if (-1 == u)
        {
            return -1;
        }
        visit[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false  && G[u][v] != INF && G[u][v] < d[v])
            {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int Prim2(int s)
{
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        if (-1 == u)
        {
            return -1;
        }
        visit[u] = true;
        ans += d[u];

        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            if (visit[v] == false && Adj[u][j].dis < d[v])
            {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

//并查集
int father[MAXV];
int findFather(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }

    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }   
    return x;
}

//通过并查集来判断两个端点是否在同一个连通块中
int Kruskal(int n, int m)
{
    int ans = 0, num_edge = 0;
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for (int i = 0; i < n; i++)
    {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV)
        {
            father[faU] = faV;
            ans += E[i].cost;
            num_edge++;
            if (num_edge == n - 1)
            {
                break;
            }
        }
    }
    if (num_edge != n - 1)
    {
        return -1;
    }
    else 
        return ans;
}



int main()
{


    return 0;
}
