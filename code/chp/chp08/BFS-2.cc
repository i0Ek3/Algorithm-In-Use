// 
// BFS-2.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-02 09:16:37
//
//
// @Question
// Maze--find the shortest steps.
// 
// Maze like this:
//
// . . . . .
//
// . * . * .
//
// . * S * .
//
// . * * * .
//
// . . . T *
// 
// '*' expression wall cannot through. '.' expression path and 'S' 'T' shows start and the end. 
//
//
 

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100;

struct node {
    int x, y;
    int step;
}S, T, Node;

int m, n;
char maze[maxn][maxn];
bool inqueue[maxn][maxn] = {false};
int X[4] = {0, 0, -1, 1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y) 
{
    if (x >= n || x < 0 || y >= 0 || y < 0)
    {
        return false;
    }
    if (maze[x][y] == '*')
    {
        return false;
    }
    if (inqueue[x][y] == true)
    {
        return false;
    }
    return true;
}

int BFS()
{
    queue<node> q;
    q.push(S);
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.x == T.x && top.y == T.y)
        {
            return top.step;
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (test(newX, newY))
            {
                Node.x = newX, Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inqueue[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m); //n x m
    for (int i = 0; i < n; i++)
    {
        getchar(); //ignore line break
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = getchar();
        }
        maze[i][m + 1] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y); //start and the end
    S.step = 0;
    printf("%d\n",BFS());

    return 0;
}


