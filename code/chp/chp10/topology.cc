// 
// topology.cc
// @ianpasm(kno30826@gmail.com)
// 2018-05-03 10:15:28
// 
// @Topology Sort
//      
//      DAG(Directed Acyclic Graph)
// 
// @Steps
//      1. defined a queue, push all node with 0 indegree
//      2. pop top then print, delete all lines out form it then indegree--, if there is some node indegree is 0 push it into queue 
//      3. loop step 2 until queue empty 
//
//
// 
//
#include <cstdio>
#include <vector>
#include <queue>

const int MAXV = 1000;
std::vector<int> G[MAXV];
int n, m, inDegree[MAXV];

bool topoloSort()
{
    int num = 0;
    std::queue<int> q; //step 1
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty()) //step 2 and 3
    {
        int u = q.front();
        printf("%d", u);
        q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i]; //v is u's post node 
            inDegree[v]--;
            if (inDegree[v] == 0) 
            {
                q.push(v);
            }   
        }
        G[u].clear(); //clear up the lines which out of node u  
        num++; 
    } 
    if (num == n) return true;
    else return false;
}

int main()
{

    return 0;
}
