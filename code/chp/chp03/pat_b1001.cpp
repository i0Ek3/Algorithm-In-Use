
//害死人不偿命的3n+1猜想

#include <iostream>
#include <cstdio>

int main()
{
    int n,step = 0;
    scanf("%d",&n);
    while(n != 1)
    {
        if (n % 2 == 0) n /= 2;
        else n = (3*n+1)/2;
        ++step;
    }
    printf("%d\n",step);
    return 0;
}
