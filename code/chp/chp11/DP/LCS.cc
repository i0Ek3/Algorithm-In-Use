// 2018-05-08
//
// LCS -- The Sum of the Largest Continous Sequence
//
// 	Given a sequence of number A1, A2, A3, ... , An, output i, j and the biggest sum of Ai + ... + Aj which i and j holds relationship: 1 <= i <= j <= n.
//
// @Question
//	In book Algorithm Notes, it's said that the largest sum of this sequence is 15 not 20 cause of dp[i] ruled end with A[i], but in this program the result is 20 followed the book.
//	So, I should check some related information now, then fixed it...
// 


#include <cstdio>
#include <algorithm>
const int maxn = 10010;

//dp[i] stored LCS end with A[i]
//A[i] stored original sequence
int dp[maxn], A[maxn]; 

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)		
	{
		scanf("%d", &A[i]);
	}

	//border
	dp[0] = A[0];
	for (int i = 1; i <= n; i++)	
	{	
		dp[i] = std::max(A[i], dp[i-1] + A[i]);
	}
	
	int k = 0;
	for (int i = 1; i <= n; i++)	
	{	
		if (dp[i] > dp[k])
		{
			k = i;
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}



