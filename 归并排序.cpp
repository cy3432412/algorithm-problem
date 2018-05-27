#include <stdio.h>
void mergeSort(int *a, int down, int up);
void Merge(int *a, int down, int mid, int up);
int a[10] = { 1,5,11,43,14,54,13,78,32,-3 };
int b[4] = { 55,66,45,7 };
int main(void)
{
	mergeSort(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}

void mergeSort(int *a, int down, int up)
{
	if (down < up)
	{
		int mid = (up + down) / 2;
		mergeSort(a, down, mid);
		mergeSort(a, mid+1, up);
		Merge(a, down, mid, up);
	}
}

void Merge(int *a, int down, int mid, int up)
{
	int L[10]; int R[10];
	int len_L = mid - down + 1;
	int len_R = up - mid;
	for (int i = 0; i < len_L; ++i)
	{
		L[i] = a[down + i];
	}
	for (int i = 0; i < len_R; ++i)
	{
		R[i] = a[mid + 1 + i];
	}
	int i = 0, j = 0, m = down;
	while (i < len_R && j < len_L)
	{
		if (L[j] > R[i])
		{
			a[m] = R[i];
			++i; ++m;
		}
		else
		{
			a[m] = L[j];
			++j; ++m;
		}
	}
	while (i < len_R)
	{
		a[m++] = R[i++];
	}
	while (j < len_L)
	{
		a[m++] = L[j++];
	}
}