#include <iostream>

long gcd(long a, long b)
{
    if (b == 0) {
        return a;
    }
    int r = a % b;
    return gcd(b, r);
}

int main()
{
    long n, m;
    scanf("%ld%ld", &n, &m);
    std::cout << "gcd is: " <<  gcd(n, m) << std::endl;
    return 0;
}

