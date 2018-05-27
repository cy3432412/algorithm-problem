/*
时间：2017.9.28
*/
#include <stdio.h>
int a[] = { 2,14,5,61,7,1,5,97,3,4,8 };
int main(void)
{
	for (int i = 1; i < sizeof(a)/sizeof(int); ++i)   //从第二个元素开始（下标为1）到最后一个元素
	{
		int t = a[i];          //中间变量t暂时存储要排序的元素
		int j = i - 1;         //j是已排序好的元素中最后一个元素的下标
		while (j >= 0 && a[j] > t)    //将已排序好的数字从后向前遍历，直到找到比待排序数字小的或遍历到第一个
		{
			a[j + 1] = a[j];       //将每个数后移
			--j;
		}
		a[j+1] = t;     //找到比t小的数后，t插入这个数后面
	}
	for (int m = 0; m < sizeof(a)/sizeof(int); ++m)
	{
		printf("%d  ", a[m]);
	}
	return 0;
}
