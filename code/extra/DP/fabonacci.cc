#include <cstdio>

const int maxn = 1000;
int n, dp[maxn];

int fact(int n)
{
	if (n == 0 | n == 1) return 1;
	else 
	{
		dp[n] = fact(n-1) + fact(n-2);
//		if (dp[n] != -1) 
//			return dp[n];
		return dp[n];
	}
}

int main()
{
	printf("Please input number n: ");
	scanf("%d", &n);
	printf("\nSo %d! = %d.", n, fact(n));

	return 0;
}
