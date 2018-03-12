// 
// isPrime.cpp
// ianpasm(kno30826@gmail.com)
// 2018-03-12 09:09:53
//
//
// Chp 5.4
// Find Prime
//
// 埃氏筛法...
//
//
 
#include <iostream>
#include <cstdio>
#include <cmath>

using std::cout;
using std::endl;

const int max = 1000;
int prime_table[max];
bool p[max]= {0};
int num = 0;

bool isPrime(int n)
{
    //cout << "Please input int n:\n";
    //cin >> n;
    if (n <= 1) return false;
    for (long long i = 2; i*i <= n; i++)
    {
        if (n % i != 0) 
            return true;
    }
    return false;
}

void find_prime()
{
    for (int i = 1; i < max; i++)
    {
        if (isPrime(i) == true)
        {
            prime_table[num++] = i;
            p[i] = true;
        }
    }
}

int main()
{
    find_prime();
    for (int i = 0; i < num; i++)
    {
        printf("%d is prime,check ok...\t\n",prime_table[i]);
    }
    return 0;
}
