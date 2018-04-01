// 
// BFS.cc
// @ianpasm(kno30826@gmail.com)
// 2018-03-31 10:12:38
//
// @Note
//
// BFS always implement by queue, and always traverse itself by level orderly.
// There is a template to use, so get it now:
//     
//     void BFS(int s)
//     {
//          queue<int> q;
//          q.push(s);
//          while (!q.empty())
//          {
//              //take top ele out;
//              //visit top ele;
//              //pop top ele;
//              //push all un-enqueue elements into queue on the next level of top and set it status with true.
//          }
//     }
//
// @Question
//
// Given m x n matrix,it's elements just includes 0 and 1.We saying position (x, y) border upon its four position 
// (x, y+1), (x, y-1), (x+1, y), (x-1, y). If there are some number 1 is bordered, then we call this number 1 formed
// a block. Please determined the block numbers in given matrix.
//
// Example given 6 x 7 matrix, it's block number is 4.
//
//
// 
//
 

#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100;

struct node {
    //position (x, y)
    int x, y; 
}Node;

//n x m matrix
int n, m;
//01 matrix
int matrix[maxn][maxn];
//mark (x, y) whether enqueue
bool inqueue[maxn][maxn] = {false};
//increment array
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0)
    {
        return false;
    }
    if (matrix[x][y] == 0 || inqueue[x][y] == true)
    {
        return false;
    }
    return true;
}

void BFS(int x, int y)
{
    queue<node> Q;
    Node.x = x, Node.y = y;
    Q.push(Node);
    inqueue[x][y] = true;
    
    while (!Q.empty())
    {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.x + Y[i];
            if (judge(newX, newY))
            {
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inqueue[newX][newY] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (matrix[x][y] == 1 && inqueue[x][y] == false)
            {
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}



