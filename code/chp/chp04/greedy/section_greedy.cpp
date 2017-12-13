 // 
 // section_greedy.cpp
 // ianpasm(kno30826@gmail.com)
 // 2017-12-13 10:10:31
 //
 //my thought:
 // definetions two array which type is int
 // one of this array be used for stored x position and other one stored y position
 // input some positions and figurd out the big section 
 // that is the biggest y position abd balabala.......
 //
 //under this is offical answer used greedy and struct to resolved this problem
 //and problem find the point on section same as this part
 //
 
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Interval {
    int x,y;
}I[maxn];

bool cmp(Interval a,Interval b)
{
    if (a.x != b.x) return a.x > b.x;
    else return a.y < b.y;
}

int main()
{
    int n;
    printf("Plz enter a number how many points you want:\n");
    while (scanf("%d",&n),n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Plz enter %dth section sparate with blank:\n",i+1);
            scanf("%d%d",&I[i].x,&I[i].y);
        }
        sort(I,I + n,cmp);
        int ans = 1;
        int lastX = I[0].x;
        for (int i = 0; i < n; i++)
        {
            if (I[i].y <= lastX)
            {
                lastX = I[i].x;
                ans++;
            }
        }
        printf("Above this we can get the most %d sections!\n",ans);
    }
    return 0;
}

