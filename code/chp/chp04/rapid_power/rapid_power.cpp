 // 
 // rapid_power.cpp
 // ianpasm(kno30826@gmail.com)
 // 2018-01-23 09:39:09
 // 

 //Given three plus intergrity a,b,m(a<10^9,b<10^18,1<m<10^9),please get result a^b%m
 //
 //if b is odd,then a^b = a * a^(b-1)
 //if b is even,then a^b = a^(b/2) * a^(2/b)
 //
 //if value a >= m,please run a % m before entry function
 //specially,if m = 1,you can regard it value as 0 and needn't calculate it's result in the function
 //

#include <cstdio>
#include <cmath>


int a ,b ,m;
typedef long long LL; //avoid int * int appearence stack overflow

//recursion

LL binaryPow1(LL a,LL b,LL m)
{
    if (0 == b)
        return 1;
    if (b & 1) //to reduce time complexity
        return a * binaryPow1(a,b-1,m) % m;
    else
    {
        LL mul = binaryPow1(a,b / 2,m);
        return mul * mul % m;
    }
}


//iteration

LL binaryPow2(LL a,LL b,LL m)
{
    LL ans = 1;
    while (b > 0)
    {
        if (b & 1) // if binary of b ending in 1
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a = 2,b = 10,m =3;
    printf("binaryPow1 = %lld\n",binaryPow1(a,b,m));
    printf("binaryPow2 = %lld\n",binaryPow2(a,b,m));

    return 0;
}
