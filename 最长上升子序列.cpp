/*
2018.5.27
�ö�̬�滮�㷨����������������еĳ���
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
	//�������ָ�����������������ռ��dp����ռ�
	printf("���ָ���:");
	int n; int result = 0;
	scanf("%d", &n);
	int *arr = (int*)malloc(n * sizeof(int));
	int *dp = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; ++i)    //����dp����
	{
		dp[i] = 1;     //��ʼ����Ϊ1
		for (int j = 0; j < i; ++j)   //����dp[i]���ҵ�j<i��a[j]<a[i]�����
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);  //����dp[i]
		}
		result = max(result, dp[i]);   //����result
	}
	printf("%d", result);
	return 0;
}

int max(int a, int b)
{
	return (a>b?a:b);
}
