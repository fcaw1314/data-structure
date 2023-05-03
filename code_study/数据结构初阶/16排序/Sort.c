#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void PrintArray(int* a,int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	//gap>1 预排序
	//gap == 1 相当于直接插入排序
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//一趟排序后打印一次
		//PrintArray(a, n);
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//交换函数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child = child + 1;
		}
		//child 大于 parent 就交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//堆排序
void HeapSort(int* a, int n)
{
	//这里采用向下调整O(n)
	//建堆算法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;

	//N*O(m=n)
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1  ; j++)
	{
		for (int i = 0; i < n - j - 1 ; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}
}


void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左边找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	//相遇后随便一个下标，然后交换
	Swap(&a[left], &a[keyi]);
	keyi = left;
	//左区间递归
	QuickSort(a, begin, keyi - 1);
	//右区间递归
	QuickSort(a, keyi + 1, end);
}