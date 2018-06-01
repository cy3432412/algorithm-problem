#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int* a, int left, int right);
int partition(int* a, int left, int right);

int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


void quick_sort(int * a, int left, int right)
{
	if (left < right)
	{
		int povit = partition(a, left, right);
		quick_sort(a, left, povit - 1);
		quick_sort(a, povit + 1, right);
	}
}


int partition(int * a, int left, int right)
{
	int pivot = a[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		
		while (i<j && a[j]>pivot)
		{
			--j;
		}
		a[i] = a[j];
		while (i < j && a[i] < pivot)
		{
			++i;
		}
		a[j] = a[i];
	}
	a[i] = pivot;
	return i;
}
