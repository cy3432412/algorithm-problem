/*
2018.5.28
01背包问题
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
	int n; int W;
	scanf("%d", &n);
	scanf("%d", &W);
	//动态生成重量数组w和价值数组v
	int* w = (int*)malloc(n * sizeof(int));
	int* v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &w[i], &v[i]);
	}
	//动态生成dp数组,dp[i+1][j]表示0~i号物品中总价值不超过j的最大价值
	int** dp = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; ++i)
	{
		dp[i] = (int*)malloc(sizeof(int)*W);
	}
	for (int i = 0; i < W; ++i)
	{
		dp[0][i] = 0;    //前0个物品中选，价值总为0
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < W; ++j)
		{   
			//判断第i号物品能不能选
			if (j < w[i])  //不能选
				dp[i + 1][j] = dp[i][j];
			else    //有可能选，判断是否要选。如果要选，dp[i][j]变为dp[i][j - w[i]]，因为要给这一件物品留出空间
				dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
		}
	}
	printf("%d", dp[n][W]);
	return 0;
}

int max(int a, int b)
{
	return (a>b?a:b);
}
