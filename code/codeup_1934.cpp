// lookup for x
// codeup 1934

#include <iostream>
#include <cstdio>

int main()
{
    int n,x;
    int num[] = {0};
    printf("plz input an num n:\n");
    scanf("%d",&n);
    printf("Plz input %d nums:\n",n);
    for(int k = 0; k < 3; k++)
    {
        scanf("%d",&n);
        num[k] += n;
    }
    printf("plz input an num x:\n");
    scanf("%d",&x);
    for (int i = 0; i < n; i++)
    {
        if((x < num[i]) || (x > num[n]))
        {
            printf("-1\n");
            break;
        }
        else
            printf("The %d's index is %d!\n",x,x-1);
    }
    return 0;
}
