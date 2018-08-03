 // 
 // pat_b1023.cpp
 // ianpasm(kno30826@gmail.com)
 // 2017-12-12 18:02:45
 //
 //
 // case:
 // input 2 2 0 0 0 3 0 0 1 0
 // output 
 
#include <cstdio>

int main()
{
    int cnt[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&cnt[i]);
    }
    for (int i = 1; i < 10; i++)
    {
        if (cnt[i] > 0)
        {
            printf("%d",i);
            cnt[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            printf("%d",i);
        }
    }
    
    return 0;
}


