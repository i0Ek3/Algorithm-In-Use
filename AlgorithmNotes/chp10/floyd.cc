// 
// floyd.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-30 16:50:49
//
// @Floyd
//
//  The shortest path of the whole source. It's suitable to use adjacent matrix to show. It has O(n^3) complexity.
//
// @Thoughts
//  
//  enum top k whose belongs to segament [1, n]
//      set top k as middle agent, enum all tops to i, j
//          if dis[i][k] + dis[k][j] < dis[i][j]
//              dis[i][j] = dis[i][k] + dis[k][j]
//
//
 
#include <cstdio>
#include <algorithm>

const int MAXV = 200;
const int INF = 0x3fffffff;
int n, m;
int dis[MAXV][MAXV];

void Floyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) 
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }   
    }
}


int main()
{

    return 0;
}

