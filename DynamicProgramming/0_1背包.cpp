#include <stdio.h>
#include <vector>

using namespace std;

int M, N;
int maxValue = 0;
int *need, *value;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	scanf("%d %d", &N, &M);
	need = new int[N + 1];
	value = new int[N + 1];
	for (int i = 1; i <= N; ++i)
	{
		getchar();
		scanf("%d %d", &need[i], &value[i]);
	}

	//vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

	//节省空间
	vector<vector<int>> dp(2, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (i % 2 == 1){
				if (j < need[i])
					dp[1][j] = dp[0][j];
				else
					dp[1][j] = max(dp[0][j], dp[0][j - need[i]] + value[i]);
			}

			if (i % 2 == 0){
				if (j < need[i])
					dp[0][j] = dp[1][j];
				else
					dp[0][j] = max(dp[1][j], dp[1][j - need[i]] + value[i]);
			}
		}
	}
	// 转移 方程  dp[i][j]= max{dp[i-1][j-1] + value[i]} 
	//dp[i][j]表示前i个物品有j大小的空间，所能获得的最大收益
	/*dp[0][0] = 0;
	for (int i = 1; i <= N; ++i)
	{
	for (int j = 1; j <= M; ++j)
	{
	if (j < need[i])
	dp[i][j] = dp[i - 1][j];
	else
	dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - need[i]] + value[i]);
	}
	}*/
	if (N % 2 == 1)
		printf("%d", dp[1][M]);
	else
		printf("%d", dp[0][M]);
	return 0;

}