#include <stdio.h>
#include <stdlib.h>
float max(float a, float b);

int main()
{
	int item;
	int money;
	float a[100][100], dp[101][101] = { 0 };
	int invest[100][100] = { 0 };   //invest[i][j]:��ǰi����ĿͶ��j��Ԫʱ������i����ĿͶ�ʵ�Ǯ��
	printf("��Ŀ����");
	scanf("%d", &item);
	printf("\n��Ͷ��Ǯ����");
	scanf("%d", &money);
	//FILE* f = fopen("C:\\Users\\wang_xin_zhou\\Desktop\\�㷨��\\11.txt", "r");
	for (int i = 1; i <= item; ++i)
	{
		for (int j = 1; j <= money; ++j)
		{
			//printf("����%d����ĿͶ��%d��Ԫʱ�Ļر���", i, j);
			//fscanf(f, "%lf", &a[i][j]);
			scanf("%f", &a[i][j]);
			//printf("\n");
		}
	}
	for (int i = 1; i <= money; ++i)
	{
		dp[1][i] = a[1][i];
	}
	for (int i = 2; i <= item; ++i)
	{
		for (int j = 0; j <= money; ++j)
		{
			for (int n = 0; n <= j; ++n)
			{
				if ((a[i][n] + dp[i - 1][j - n]) > dp[i][j])
				{
					invest[i][j] = n;
					dp[i][j] = a[i][n] + dp[i - 1][j - n];
				}
			}
		}
	}
	printf("������%.2f��Ԫ\n", dp[item][money]); 
	int rest = money;
	int sum = 0;
	for (int i = item; i >= 2; --i)
	{
		printf("����%d����ĿͶ��%d��Ԫ, ����%.2f��Ԫ\n", i, invest[i][rest], a[i][invest[i][rest]]);
		sum += invest[i][rest];
		rest -= invest[i][rest];
	}
	printf("����1����ĿͶ��%d��Ԫ������%.2f��Ԫ\n", money - sum, a[1][money - sum]);
	return 0;
}

float max(float a, float b)
{
	return a>b?a:b;
}
