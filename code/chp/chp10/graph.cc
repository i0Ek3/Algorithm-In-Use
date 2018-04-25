// 
// graph.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-25 10:15:28
//
// @Graph
//
// @Defination 
//  G(V, E) is a graph. A graph can be divided deirective graph and indeirective graph.
//
// @The ways of torage for Graph
//  The ways of storage for graph are two: one is adjacency matrix, other is adjancency link.
//
// @Traverse for Graph
//  BFS
//  DFS
//


//usr vector to impelement adjancency link
//vector<int> Adj[N]
//struct Node {
//    int v, w; //
//
//    //constructor function
//    Node(int _v, int _w)
//    : v(_v)
//    , w(_w)
//    {}
//    
//    //instance for add lines of graph
//    //Adj[1].push_back(Node(3, 4));
//};

#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV]; 
bool visit[MAXV] = {false};
vector<int> Adj[MAXV];


//1. Adjacency matrix
void DFS4matrix(int u, int depth) //u is current visit top-node's id
{
    visit[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (visit[v] == false && G[u][v] != INF) //u can be visited and throughable
        {
            DFS4matrix(v, depth + 1); //visit u and add value to depth
        }
    }
}

void DFSTrave4matrix()
{
    for (int u = 0; u < n; u++)
    {
        if (visit[u] == false)
        {
            DFS4matrix(u, 1);
        }
    }
}


//2. Adjacency link
void DFS4link(int u, int depth)
{
    visit[u] = true;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (visit[u] == false)
        {
            DFS4link(v, depth + 1);
        }
    }
}

void DFSTrave4link()
{
    for (int u = 0; u < n; u++)
    {
        if (visit[u] == false)
        {
            DFS4link(u, 1);
        }
    }
}


int main()
{



    return 0;
}



