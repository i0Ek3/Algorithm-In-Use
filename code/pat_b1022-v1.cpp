//PAT B1022 D进制的A+B
//输入非负整数A,B以及D进制数
//输出A+B的D进制数1<D<=10
//
//进制转换基本思路:
//  1.P(x)-->10(y)
//  2.10(y)-->Q(z)
//
//本题思路:
//  P=10
//  y=A+B
//  10(y)-->D(z)
//  D=2

#include <cstdio>

void convert(int a,int b,int d)
{
    int z[31]; //用来存放转换结果
    int num = 0;
    int ans = a + b;

    do
    {
        z[num++] = ans % d;
        ans /= d;
    }while(ans != 0);

    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d",z[i]);
    }
}

int main()
{
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);
    convert(a,b,d);
    return 0;
}
