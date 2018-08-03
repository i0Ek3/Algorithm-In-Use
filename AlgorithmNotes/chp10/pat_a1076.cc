// 
// pat_a1076.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-26 16:35:35
// 
// @Forwards on Weibo
//
//
 
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int MAXV = 1010;

struct Node 
{
    int id;
    int layer;
};

std::vector<Node> Adj[MAXV]; //Adjacent link
bool inqueue[MAXV] = {false};

int BFS(int s, int L)
{
    int numForward = 0;
    std::queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inqueue[start.id] = true;
    while (!q.empty())
    {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id; //top node's id 
        for (int i = 0; i < Adj[u].size(); i++)
        {
            Node next = Adj[u][i]; //start at u can reached node next
            next.layer = topNode.layer + 1;
            if (inqueue[next.id] == false && next.layer <= L)
            {
                q.push(next);
                inqueue[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}


int main()
{
    Node user;
    int n, L, numForward, idFollow;
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        user.id = i;
        scanf("%d", &numForward);
        for (int j = 0; j < numForward; j++)
        {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user); //line idFollow -> i
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery); //the number of query 
    for (int i = 0; i < numQuery; i++)
    {
        memset(inqueue, false, sizeof(inqueue));
        scanf("%d", &s);
        int numForward = BFS(s, L);
        printf("%d\n", numForward);
    }
    return 0;
}
