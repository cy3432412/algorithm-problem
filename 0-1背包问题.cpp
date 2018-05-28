/*
2018.5.28
01��������
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
	int n; int W;
	scanf("%d", &n);
	scanf("%d", &W);
	//��̬������������w�ͼ�ֵ����v
	int* w = (int*)malloc(n * sizeof(int));
	int* v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &w[i], &v[i]);
	}
	//��̬����dp����,dp[i+1][j]��ʾ0~i����Ʒ���ܼ�ֵ������j������ֵ
	int** dp = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; ++i)
	{
		dp[i] = (int*)malloc(sizeof(int)*W);
	}
	for (int i = 0; i < W; ++i)
	{
		dp[0][i] = 0;    //ǰ0����Ʒ��ѡ����ֵ��Ϊ0
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < W; ++j)
		{   
			//�жϵ�i����Ʒ�ܲ���ѡ
			if (j < w[i])  //����ѡ
				dp[i + 1][j] = dp[i][j];
			else    //�п���ѡ���ж��Ƿ�Ҫѡ�����Ҫѡ��dp[i][j]��Ϊdp[i][j - w[i]]����ΪҪ����һ����Ʒ�����ռ�
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
