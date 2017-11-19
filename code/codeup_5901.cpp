//回文串
//12321 level ava &8&
//思路:将输入的字符存入数组中
//判断数组中从前往后和从后往前对应的数是否相等
//偶数不可能为回文数
//
#include <stdio.h>
#include <cstring>

int main()
{
    char str[256];
    int i;
    
    while(scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        if(len % 2 == 0)//even不可能为回文数 
        {
            printf("NO\n");
        }
        else//odd进一步判断
        {
            for(i = 0; i < len/2; i++)
            {
                if(str[i] != str[len-i-1])
                {
                    printf("NO\n");
                }
                else
                {
                    printf("YES\n");
                }
            }
        }
    }
    return 0;
}
