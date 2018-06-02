#include <stdio.h>
#include <stdlib.h>

void swap(float &i, float &j);
float select(float arr[], int left, int right, int k);

int main()
{
	int n;
	int k;
	float min_k;
	printf("数字的个数:");
	scanf("%d", &n);
	printf("第k小的数字:");
	scanf("%d", &k);
	float* arr = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i<n; ++i)
	{
		scanf("%f", &arr[i]);
	}
	if (k<1 || k>n)
		printf("输入有误!\n");
	else
		min_k = select(arr, 0, n - 1, k);
	printf("第%d小的数字为:%.2f\n", k, min_k);
	return 0;
}

void swap(float &i, float &j)
{
	float t = i;
	i = j;
	j = t;
}

float select(float arr[], int left, int right, int k)
{
	int pivot = arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i<j && arr[j]>pivot)
		{
			--j;
		}
		arr[i] = arr[j];
		while (i < j && arr[i] < pivot)
		{
			++i;
		}
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	if ((i - left + 1) == k)
		return pivot;
	else if ((i - left + 1) < k)
		return select(arr, i + 1, right, k - (i - left + 1));
	else
		return select(arr, left, j - 1, k);
}