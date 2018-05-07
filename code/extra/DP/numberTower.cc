

#include <cstdio>
#include <algorithm>

const int maxn = 1000;
int fac[maxn][maxn], dp[maxn][maxn];

int main()
{
	int n;
	scanf("%d", &n);	

	for (int i = 1; i <= n; i++)	
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &fac[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{	
		dp[n][i] = fac[n][i];
	}

	for (int i = n-1; i >= 1; i--)
	{	
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = std::max(dp[i+1][j],dp[i+1][j+1]) + fac[i][j];
		}
	}
	printf("%d\n", dp[1][1]);
	
	return 0;
}


