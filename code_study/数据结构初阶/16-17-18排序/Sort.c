#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
#include "Stack.h"
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

//三数取中
int GetmidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	// a[begin]   a[mid]    a[end]
	// a[begin[ < a[mid[
	if (a[begin] < a[mid])
	{
		//a[begin] < a[mid] < a[end]
		if (a[mid] < a[end])
		{
			return mid;
		}
		//a[mid] > a[end] 再次判断
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	// a[begin] > a[mid]
	else
	{
		//a[mid] > a[end]
		if (a[mid] > a[end])
		{
			return mid;
		}
		//a[mid] < a[end]
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

//Hoare 版本
int PartSort1(int* a , int begin , int end)
{
	int mid = GetmidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

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
	
	return keyi;
}

//挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetmidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin;
	int right = end;
	int key = a[left];
	int hole = left;

	while (left < right)
	{
		//右边先走，找小于key的
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//左边找大于key的;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	while (cur <= end)
	{
		//cur 先走
		if (a[cur] <= a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
			cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

//快速排序(递归)
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
		if ((end - begin + 1) < 15)
	{
		//小区间用直接插入排序，减少递归调用次数
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
			int keyi = PartSort3(a, begin, end);
		//左区间递归
		QuickSort(a, begin, keyi - 1);
		//右区间递归
		QuickSort(a, keyi + 1, end);
	}
	
}

//快速排序(非递归)
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		// [left , keyi-1]  keyi  [keyi+1 , right]
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
		if (keyi - 1 > left)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}


void _MergeSort(int* a ,int begin ,int end,int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	//[begin , mid] [ mid +1 , end] 递归子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc: fail ");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

//归并非递归排序
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc: fail ");
		exit(-1);
	}

	// 归并每组数据个数，从1开始，
	//因为1个认为是有序的，可以直接归并
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			// [begin1,end1]  [begin2,end2] 归并
			int begin1 = i; 
			int end1 = i + rangeN - 1;
			int begin2 = i + rangeN;
			int end2 = i + 2 * rangeN - 1;
			int j = i;

			//end1越界
			if(end1 >=n)
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			//begin2 , end2越界
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			//end2越界
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}


//快速排序针对相同数据的优化
//三路划分解决
//详解已经发到gitee


//计数排序
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	//找出最大值，最小值
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	//开一个数组
	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int) * range);
	if (countArr == NULL)
	{
		perror("calloc fail");
		exit(-1);
	}
	//1.统计次数
	for (int i = 0; i < n; ++i)
	{
		countArr[a[i] - min]++;
	}
	//2.排序
	int k = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			a[k++] = i + min;
		}
	}
	free(countArr);

}