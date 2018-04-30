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
int G[MAXV][MAXV], d[MAXV];
bool vis[MAXV] = {false};
std::vector<Node> Adj[MAXV];

//Adjacent Matrix
void DijkstraM(int s)
{
    std::fill(d, d + MAXV, INF); //intial
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
            }
        }
    }
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
