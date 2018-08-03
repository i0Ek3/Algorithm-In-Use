// 
// pat_a1059.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-17 09:07:29
// 
// PAT_A1059 Prime Factors
// Given a postive integer N,output format following as: N = p1^k1 * p2^k2 * ... * pm*km.
// 
// case:
//  97532468
//  97532468=2^2*11*17*101*1291
//
// GG,no mood to find the issue,fixed next time.
//
//
 
#include <cstdio>
#include <cmath>

const int maxn = 100010;
int prime[maxn],num = 0;

struct factor
{
    int x,cnt; //x is prime factor, cnt is its numbers.
}fac[10];

bool is_prime(int n) //judge n whether is prime.
{
    if (n == 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void find_prime() //find the prime table.
{
    for (int i = 1; i < maxn; i++)
    {
        if (is_prime(i) == true)
        {
            prime[num++] = i;
        }
    }
}

int main()
{
    find_prime();
    int n,num = 0;
    scanf("%d",&n);
    if (n == 1) printf("1=1"); // special judge.
    else
    {
        printf("%d=",n);
        int sqr = (int)sqrt(1.0 * n); //equal with sqrt(n).
        for (int i = 0; i < num && prime[i] <= sqr; i++) //enum numbers in sqrt(n).
        {
            if (n % prime[i] == 0)
            {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while(n % prime[i] == 0) //calculate the numbers of prime factors.
                {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) break;
        }
        
        if (n != 1) //there is a prime factor which is lager than sqrt(n) and cannot divided by it.
        {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        
        for (int i = 0; i < num; i++) //output as following format:
        {
            if (i > 0) printf("*");
            printf("%d",fac[i].x);
            if (fac[i].cnt > 1) printf("^%d",fac[i].cnt);
        }           
    } 
    return 0;
}

