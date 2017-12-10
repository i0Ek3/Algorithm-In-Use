//图形输出之codeup版本

#include <iostream>
#include <cstdio>

int main()
{
    int row,col;
    char ch;
    scanf("%d %c",&col,&ch);
    if(col % 2 == 1)
        row = col / 2 + 1;
    else
        row = col / 2;
    
    for(int i = 0; i < col; i++)
    {
        printf("%c",ch);
    }
    printf("\n");

    for(int i = 2; i < row; i++)
    {
        printf("%c",ch);
        for(int j = 0; j < col - 2; j++)
        {
            printf(" ");
        }
        printf("%c\n",ch);
    }

    for(int i = 0; i < col; i++)
    {
        printf("%c",ch);
    }

    return 0;
}
