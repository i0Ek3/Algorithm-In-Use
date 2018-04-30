// 
// bellman.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-30 16:38:09
//
// @Bellman-Ford + SPFA
//      
//  Bellman-Ford algorithm: to solve the shortest path of weight with negative graph, it has O(VE) time complexity.
//  SPFA(Shortest Path Faster Algorithm): updated the Bellman-Ford algorithm's performance, it has O(kE) time complexity.
//
//
//
 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
const int MAXV = 1000;
const int INF = 0x3fffffff;

struct Node
{
    int v, dis;
};

std::vector<Node> Adj[MAXV];
int n, d[MAXV], num[MAXV];
bool inqueue[MAXV];


// adjacent link
bool BellmanFord(int s) //s is origin
{
    std::fill(d, d + MAXV, INF);
    d[s] = 0;

    // solve array d
    for (int i = 0; i < n - 1; i++) // needs round n - 1 to loop
    {
        for (int u = 0; u < n; u++) // traverse all top
        {
            for (int j = 0; j < Adj[u].size(); j++)
            {
                int v = Adj[u][v].v; // adjacent line's top
                int dis = Adj[u][v].dis; // weight of adjacent lines
                if (d[u] + dis < d[v]) // update d[v] make it smaller
                {
                    d[v] = d[u] + dis;
                }
            }  
        } 
    }

    // judge negative ring
    for (int u = 0; u < n; u++) //judge every lines
    {
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][v].v;
            int dis = Adj[u][v].dis;
            if (d[u] + dis < d[v]) 
            {
                return false; //reached negative ring
            }
        }
    }

    return true;
}

// adjacent link
bool SPFA(int s)
{
    //intial
    memset(inqueue, false, sizeof(inqueue));
    memset(num, 0, sizeof(num));
    std::fill(d, d + MAXV, INF);
    
    std::queue<int> q;
    q.push(s);
    inqueue[s] = true;
    num[s]++;
    d[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][v].v;
            int dis = Adj[u][v].dis;
            if (d[u] + dis < d[v])
            {
                d[v] = d[u] + dis;
                if (!inqueue[v])
                {
                    q.push(v);
                    inqueue[v] = true;
                    num[v]++;
                    if (num[v] >= n)
                    {
                        return false; //exist reached negative ring
                    }
                }
            }
        }
    }
    return true;
}


int main()
{



    return 0;
}
