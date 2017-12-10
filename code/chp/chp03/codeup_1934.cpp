// lookup for x
// codeup 1934
// 原题是输入不同的几个值,你也可以考虑输入几个连续且相同的数字

#include <iostream>
#include <cstdio>
const int maxn = 210;
int num[maxn];

int main()
{
    int n,x,k;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&num[i]);
        scanf("%d",&x);
        for(k = 0; k < n; k++)
        {
            if(num[k] == x)
            {
                printf("%d\n",k);
                break;
            }
        }
        if(k == n) printf("-1\n");
    }
    return 0;
}
