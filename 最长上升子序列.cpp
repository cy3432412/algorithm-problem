/*
2018.5.27
用动态规划算法计算最大上升子序列的长度
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
	//输入数字个数，分配序列数组空间和dp数组空间
	printf("数字个数:");
	int n; int result = 0;
	scanf("%d", &n);
	int *arr = (int*)malloc(n * sizeof(int));
	int *dp = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; ++i)    //计算dp数组
	{
		dp[i] = 1;     //初始化都为1
		for (int j = 0; j < i; ++j)   //计算dp[i]，找到j<i且a[j]<a[i]的情况
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);  //更新dp[i]
		}
		result = max(result, dp[i]);   //更新result
	}
	printf("%d", result);
	return 0;
}

int max(int a, int b)
{
	return (a>b?a:b);
}
