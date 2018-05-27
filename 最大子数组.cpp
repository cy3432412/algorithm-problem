#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void MaxArr(int* a, int low, int high, int* arr_left, int* arr_right, int* arr_sum);
void MaxCrossArr(int* a, int low, int mid, int high, int* left, int* right, int *arr_sum);
int a[] = { 34, 32, -1, 46, -2, -14, 43, 87, 14, 56 };
int main(void)
{
	int arr_left, arr_right, arr_sum;
	MaxArr(a, 0, 9, &arr_left, &arr_right, &arr_sum);
	for (int i = arr_left; i <= arr_right; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n最大子数组和为%d", arr_sum);
	return 0;
}

void MaxArr(int* a, int low, int high, int* arr_left, int* arr_right, int* arr_sum)
{
	int cross_low, cross_high, cross_sum, left_low, left_high, left_sum, right_low, right_high, right_sum;
	int mid = (low + high) / 2;
	if (high == low)
	{
		*arr_left = *arr_right = high;
		*arr_sum = a[high];
	}
	else
	{
		MaxArr(a, low, mid, &left_low, &left_high, &left_sum);
		MaxArr(a, mid + 1, high, &right_low, &right_high, &right_sum);
		MaxCrossArr(a, low, mid, high, &cross_low, &cross_high, &cross_sum);
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			*arr_left = left_low;
			*arr_right = left_high;
			*arr_sum = left_sum;
		}
		else if (right_sum >= left_sum&&right_sum >= cross_sum)
		{
			*arr_left = right_low;
			*arr_right = right_high;
			*arr_sum = right_sum;
		}
		else
		{
			*arr_left = cross_low;
			*arr_right = cross_high;
			*arr_sum = cross_sum;
		}
	}
}

void MaxCrossArr(int* a,int low, int mid, int high, int* left, int* right, int *arr_sum)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int left_max, right_max;
	int sum = 0;
	int i;
	for (i = mid; i >= low; --i)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			left_max = i;
		}
	}
	*left = left_max;
	*arr_sum = sum;
	sum = 0;
	for (i = mid + 1; i <= high; ++i)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			right_max = i;
		}
	}
	*right = right_max;
	*arr_sum += sum;
}