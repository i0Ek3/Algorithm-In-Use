// 
// dijkstra.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-29 20:45:43
//
// @Dijkstra -- The Shortest Path of Single Source 
//      
//  @Defination
//      Given any graph G(V, E) and origin S, terminate T, determine the shortest path from S to T.
//
//  @Thought
//      Defined a set s to save visited top for G(V, E)
//      Then choose the smallest distance node u add to s 
// 
//  @Questions
//      1. Add new weight of line
//
//          for (int v = 0; v < n; v++)
//          {
//              if (vis[v] == false && G[u][v] != INF)
//              {
//                  if (d[u] + G[u][v] < d[v])
//                  {
//                      d[v] = d[u] + G[u][v];
//                      c[v] = c[u] + cost[u][v]; //cost[u][v] is u->v's cost
//                  }
//                  else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v])
//                  {
//                      c[v] = c[u] + cost[u][v];
//                  }
//              }
//          }
//
//      2. Add new weight of point
//
//          for (int v = 0; v < n; v++)
//          {
//              if (vis[v] == false && G[u][v] != INF)
//              {
//                  if (d[u] + G[u][v] < d[v])
//                  {
//                      d[v] = d[u] + G[u][v];
//                      w[v] = w[u] + weight[u][v]; 
//                  }
//                  else if (d[u] + G[u][v] == d[v] && w[u] + weight[u][v] < w[v])
//                  {
//                      w[v] = w[u] + weight[u][v];
//                  }
//              }
//          }
//          
//
//      3. Ask the numbers of the shortest path(s)
//
//          for (int v = 0; v < n; v++)
//          {
//              if (vis[v] == false && G[u][v] != INF)
//              {
//                  if (d[u] + G[u][v] < d[v])
//                  {
//                      d[v] = d[u] + G[u][v];
//                      num[v] = num[u];
//                  }
//                  else if (d[u] + G[u][v] == d[v])
//                  {
//                      num[v] += num[u];
//                  }
//              }
//          }
//          
//
//
//
//
//
//

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct Node 
{
    int otop, dis; //otop is object top, dis is weight of line
};

int n; //numbers of top
const int MAXV = 1000;
const int INF = 1000000000;
int G[MAXV][MAXV], d[MAXV], pre[MAXV];
bool vis[MAXV] = {false};
std::vector<Node> Adj[MAXV];

//Adjacent Matrix
void DijkstraM(int s)
{
    std::fill(d, d + MAXV, INF); //intial
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
    }

    d[s] = 0;
    
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int MIN = INF;
        
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        if (-1 == u)
        {
            return;
        }

        vis[u] = true;
        
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
}

//output path 
void DFS(int s, int v)
{
    if (v == s)
    {
        printf("%d\n", s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d->", v);
}

//Adjacent Link
void DijkstraL(int s)
{
    std::fill(d, d + MAXV, INF);
    d[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int MIN = INF;

        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        if (-1 == u)
        {
            return;
        }

        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][v].otop;
        
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
            {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }   
}



int main()
{


    return 0;
}
