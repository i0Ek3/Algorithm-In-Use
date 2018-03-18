// 
// big_numbers_add.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-18 09:26:32
// 
 
#include <cstdio>
#include <cstring>

struct bign {
    int d[10000];
    int len;
    bign() {
        memset(d,0,sizeof(d));
        int len = 0;
    }
};

bign reverse(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign add(bign a,bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int sum = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = sum % 10;
        carry = sum / 10;
    }
    if (carry != 0) c.d[c.len++] = carry;
    return c;
}

void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d",a.d[i]);
    }
}

int main()
{
    char str1[10000],str2[10000];
    scanf("%s%s",str1,str2);
    bign a = reverse(str1);
    bign b = reverse(str2);
    print(add(a,b));
    return 0;
}




